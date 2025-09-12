#!/bin/bash

pass=0;
failed=0;

echo "Running invalid test"
for map in invalid_maps/*.cub; do
	echo "Testing map: $map"
	valgrind --leak-check=full --error-exitcode=42 ./cub3D "$map"
	if [ $? -ne 0 ]; then
		echo "PASS $map (correctly failed)"
		((pass++))
	else
		echo "Failed $map (should fail but passed)"
		((failed++))
	fi
done

echo "Running valid test"
for map in valid_maps/*.cub; do
	echo "Testing map: $map"
	valgrind --leak-check=full --error-exitcode=42 ./cub3D "$map"
	if [ $? -eq 0 ]; then
		echo "PASS $map (correctly pass)"
		((pass++))
	else
		echo "Failed $map (should pass but failed)"
		((failed++))
	fi
done

echo "Summary"
echo "Pass tests => $pass"
echo "failed tests => $failed"
