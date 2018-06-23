it = 3;
summer = 2;
diagonals(1) = 1;
for i=2:2001
	if mod(i,4) == 1
		summer = summer + 2;
	end
	diagonals(i) = it;
	it = it + summer;
end

result = sum(diagonals);
fprintf("Sum of diagonals = %d\n",result);