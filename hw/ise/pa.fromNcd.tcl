
# PlanAhead Launch Script for Post PAR Floorplanning, created by Project Navigator

create_project -name ttk -dir "Y:/Documents/Workspaces/XilinxWorkspace/ttk/planAhead_run_2" -part xc6vlx240tff1156-1
set srcset [get_property srcset [current_run -impl]]
set_property design_mode GateLvl $srcset
set_property edif_top_file "Y:/Documents/Workspaces/XilinxWorkspace/ttk/main.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {Y:/Documents/Workspaces/XilinxWorkspace/ttk} {ipcore_dir} }
add_files [list {ipcore_dir/dut_monitor.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "main.ucf" [current_fileset -constrset]
add_files [list {main.ucf}] -fileset [get_property constrset [current_run]]
link_design
read_xdl -file "Y:/Documents/Workspaces/XilinxWorkspace/ttk/main.ncd"
if {[catch {read_twx -name results_1 -file "Y:/Documents/Workspaces/XilinxWorkspace/ttk/main.twx"} eInfo]} {
   puts "WARNING: there was a problem importing \"Y:/Documents/Workspaces/XilinxWorkspace/ttk/main.twx\": $eInfo"
}
