### Esp node server  
meant to work with the https://github.com/Supereg/homebridge-http-humidity-sensor
and https://github.com/Supereg/homebridge-http-temperature-sensor.

the configuration should look like:
```
{
    "accessories": [
        {
          "accessory": "HTTP-HUMIDITY",
          "name": "Humidity Sensor",
          
          "getUrl": "http://local_esp_ip_address_goes_here/api/getHumidity"
        },
        {
          "accessory": "HTTP-TEMPERATURE",
          "name": "Temperature Sensor",
          
          "getUrl": "http://local_esp_ip_address_goes_here/api/getTemperature"
        }
    ]
}
```
