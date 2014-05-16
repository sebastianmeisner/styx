
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name ttk -dir "C:/Users/meise/ise_projects/ttk_rev2/planAhead_run_2" -part xc6vlx240tff1156-1
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "C:/Users/meise/ise_projects/ttk_rev2/main.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Users/meise/ise_projects/ttk_rev2} {ipcore_dir} }
add_files [list {ipcore_dir/dut_monitor.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "C:/Users/meise/ise_projects/Dynamische Rekonfiguration/data/main3.ucf" [current_fileset -constrset]
add_files [list {C:/Users/meise/ise_projects/Dynamische Rekonfiguration/data/main3.ucf}] -fileset [get_property constrset [current_run]]
link_design
