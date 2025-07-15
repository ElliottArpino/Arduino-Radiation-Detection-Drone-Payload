% ESP32 IP address and port
esp32IP = '172.20.10.3'; % ESP32's IP address
esp32Port = 80;

% Initialize the matrix to store all data
collectedData = []; % Columns: [timestamp, radiation, latitude, longitude, altitude]

% Continuously fetch data every 10 seconds
while true
    try    
        % Fetch the latest log from the ESP32
        logData = webread(['http://' esp32IP ':' num2str(esp32Port)]);
        
        % Split the data into separate components by space
        dataParts = str2double(strsplit(strtrim(logData)));
        
        % Check if the data is valid
        if numel(dataParts) == 4
            % Extract the radiation, latitude, longitude, and altitude values
            radiationValue = dataParts(1);   % Radiation level
            latitudeValue = dataParts(2);    % Latitude
            longitudeValue = dataParts(3);   % Longitude
            altitudeValue = dataParts(4);    % Altitude
            
            % Get the current timestamp
            timestamp = datetime('now');
            timestampNumber = datenum(timestamp); % Convert to numeric format for storage
            
            % Append the new data as a row in the matrix
            collectedData(end + 1, :) = [timestampNumber, radiationValue, latitudeValue, longitudeValue, altitudeValue];
            
            % Output the new values every time data is fetched
            fprintf('Timestamp: %s | Radiation Level: %.2f µSv/h | Latitude: %.4f | Longitude: %.4f | Altitude: %.2f meters\n', ...
                    timestamp, radiationValue, latitudeValue, longitudeValue, altitudeValue);
            
            % Save the collected data matrix into a .mat file
            save('collectedData.mat', 'collectedData');
        else
            warning('Received data is incomplete or malformed: %s', logData);
        end
        
    catch ME
        % Handle errors gracefully
        warning('Failed to fetch data: %s', ME.message);
    end
    
    % Pause before the next request (10 seconds)
    pause(10); 
end
