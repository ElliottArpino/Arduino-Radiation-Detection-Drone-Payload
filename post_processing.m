% Load data from the file
load('collecteddata.mat'); % Assuming 'collectedData' is loaded

% Remove the first 100 rows
collectedData(1:230, :) = [];

% Remove rows where columns 3, 4, or 5 have a value of 0
validRows = collectedData(:, 3) ~= 0 & collectedData(:, 4) ~= 0 & collectedData(:, 5) ~= 0;
filteredData = collectedData(validRows, :);

% Extract data
latitudes = filteredData(:, 3);
longitudes = filteredData(:, 4);
radiationLevels = filteredData(:, 2);

% Create a map figure
figure;
geoscatter(latitudes, longitudes, 50, radiationLevels, 'filled');
colorbar; % Show color scale for radiation levels

% Adjust the color bar scale to show better variation
caxis([min(radiationLevels), max(radiationLevels)]);

% Add title and set basemap
title('Radiation Levels - Scatter Map');
geobasemap('satellite'); % Set the basemap

