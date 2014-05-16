filename = 'Fehler_75Grad_300_test (2).csv';
M = csvread(filename);
sub_div = 2;                % # of subdivisions in 0->1, 1->2, ... , 4->5 
width1 = 0.2;               % bar width
err_dist = zeros(1,5);
[rows,cols] = size(M);
seconds = M(1:rows,1);      % Seconds
err_sec = M(1:rows,2);      % # of errors per second
%err_cum = M(1:rows,3);  
freq_buff = M(1:rows,9);
freq_buff = freq_buff/1000;
frequency = 365.000:0.1:389.000;
y = zeros(1,numel(frequency));
div_resol = 1/sub_div;
num_divisions = sub_div * 5;

i = 0;
j = 0;
index = 1;
curr_freq = 0;
figure;
bar(frequency,y,width1,'FaceColor',[1.0,1.0,1.0],'EdgeColor','none');   % plot a dummy graph to mark the axis
xlim([358 390]);            % set the limits of x-axis
hold on                 

freqz_observed = floor(numel(freq_buff)/600);                   % total number of frequencies configured
err_count = zeros(freqz_observed,num_divisions+1);              % used to store error distribution at a particular frequency to a file thats why num_division plus frequency.
for i = 1:freqz_observed
    err_dist = zeros(1,num_divisions);                          % bar overlay initialisation
    curr_freq = freq_buff(index+1,1);
    err_count(i,1) = curr_freq;
    for j = 1:600
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
        bar(curr_freq,k/sub_div,width1,'FaceColor',[1.0*err_dist(1,k)/600,0.33,1.0-(1.0*err_dist(1,k)/600)],'EdgeColor','none');
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
caxis([0 600]);
colormap(cm);
%colorbar('YTickLabel','0', '100', '200', '300', '400', '500', '600');
colorbar;