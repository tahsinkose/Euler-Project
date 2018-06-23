index = 1;
for a=2:100
	for b=2:100
		terms(index) = a^b;
		index = index + 1;
	end
end

result = unique(terms);

m = size(result,2);
fprintf("Total number of terms = %d\n",m);
clc;
clear;