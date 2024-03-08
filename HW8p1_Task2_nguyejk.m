clear; clc;
T = readmatrix("Temperature.txt");

results = zeros(4, 3);

for year = 1:4
    for day = 1:size(T,1)
        tempDiff = T(day, year+1) - T(day, year);
        
        if tempDiff > 0
            results(year, 1) = results(year, 1) + 1;
        elseif tempDiff < 0
            results(year, 3) = results(year, 3) + 1;
        else
            results(year, 2) = results(year, 2) + 1;
        end
    end
end

for i = 1:4
    fprintf('Comparing %d to %d: there were %d Increases, %d Equal, %d Decreases\n', ...
        1950+i, 1951+i, results(i, 1), results(i, 2), results(i, 3));
end

