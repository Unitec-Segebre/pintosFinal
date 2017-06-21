include ../Makefile.kernel

do_the_thing:
	make clean
	make -j4
	make disk
	make run_programs

disk_and_programs:
	make disk
	make run_programs

disk:
	pintos-mkdisk build/run-programs.dsk --filesys-size=10
	
run_programs:
	pintos --qemu --disk=build/run-programs.dsk -- -f -q
	pintos --qemu --disk=build/run-programs.dsk -p ../examples/bubsort -a bubsort -- -q
	pintos --qemu --disk=build/run-programs.dsk -p ../examples/run-hi -a run-hi -- -q
	pintos --qemu --disk=build/run-programs.dsk -p ../examples/ls -a ls -- -q
	pintos --qemu --disk=build/run-programs.dsk -p ../examples/run-programs -a run-programs -- -q
	pintos --qemu --disk=build/run-programs.dsk -- run run-programs

run_programs_no_build:
	pintos --qemu --disk=build/run-programs.dsk -- run run-programs