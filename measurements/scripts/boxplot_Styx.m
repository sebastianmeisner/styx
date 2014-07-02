clear;
filename = 'serial700.csv';
%filename = 'serial.csv';
fid=fopen(filename);
line = fgetl(fid);
fclose(fid);
total_col = length(find(line==','));

freq_test_time = 50;


start_row = 2501;  start_col = 0;
end_row = start_row + freq_test_time*50;   
%end_row = 133400;
end_col = total_col;

%M = csvread(filename,start_row, start_col,[start_row, start_col, end_row, end_col]);
M = csvread(filename,start_row,start_col,[start_row start_col end_row end_col]);

sub_div = 2;                % # of subdivisions in 0->1, 1->2, ... , 4->5 
width1 = 0.2;               % bar width
err_dist = zeros(1,5);
[rows,cols] = size(M);
seconds = M(1:rows,1);      % Seconds
err_sec = M(1:rows,2);      % # of errors per second
%err_cum = M(1:rows,3);  
freq_buff = M(1:rows,8);
freq_buff = freq_buff/1000;
frequency = freq_buff(1):0.01:freq_buff(rows);
y = zeros(1,numel(frequency));
div_resol = 1/sub_div;
num_divisions = sub_div * 5;

i = 0;
j = 0;
index = 1;
curr_freq = 0;
figure;
bar(frequency,y,width1,'FaceColor',[1.0,1.0,1.0],'EdgeColor','none');   % plot a dummy graph to mark the axis
xlim([freq_buff(1)-2 freq_buff(rows)+2]);            % set the limits of x-axis
hold on                 

freqz_observed = floor(numel(freq_buff)/freq_test_time);                   % total number of frequencies configured
err_count = zeros(freqz_observed,num_divisions+1);              % used to store error distribution at a particular frequency to a file thats why num_division plus frequency.
for i = 1:freqz_observed
    err_dist = zeros(1,num_divisions);                          % bar overlay initialisation
    curr_freq = freq_buff(index+1,1);
    err_count(i,1) = curr_freq;
    for j = 1:freq_test_time
        if err_sec(index,1) == 0
            err_dist(1) = err_dist(1) + 1;
        else
            value = log10(err_sec(index,1));
            frac = value - floor(value);
            matched_div = 1;
            for div = div_resol:div_resol:1
                if frac <= div
                    break;
                end
                matched_div = matched_div + 1;
            end
            value = floor(value) * sub_div + matched_div;
            err_dist(1,value) = err_dist(1,value) + 1;
        end
        index = index + 1;
    end
    err_count(i,2:num_divisions+1) = err_dist(1,:);
    for k = num_divisions:-1:1                                  % Plot bars
        bar(curr_freq,k/sub_div,width1,'FaceColor',[1.0*err_dist(1,k)/freq_test_time,0.33,1.0-(1.0*err_dist(1,k)/freq_test_time)],'EdgeColor','none');
    end
end

title('Frequency vs Errors per second');
%h = get(gca, 'title');
%set(h, 'FontSize', 14);
xlabel('Frequency (MHz)');
% h = get(gca, 'xlabel');
% set(h, 'FontSize', 14);
ylabel('# of errors per second (logarithmic)');
% h = get(gca, 'ylabel');
% set(h, 'FontSize', 14);
load('mycmap.mat');
caxis([0 freq_test_time]);
colormap(cm);
%colorbar('YTickLabel','0', '100', '200', '300', '400', '500', '600');
colorbar;
hold off;