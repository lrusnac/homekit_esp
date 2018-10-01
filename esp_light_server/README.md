### Esp light server  
meant to work with the https://github.com/Supereg/homebridge-http-switch plugin.

the configuration should look like:
```
{
    "accessories": [
        {
          "accessory": "HTTP-SWITCH",
          "name": "Sofa light",
          
          "switchType": "stateful",
          
          "onUrl": "http://local_esp_ip_address_goes_here/api/on",
          "offUrl": "http://local_esp_ip_address_goes_here/api/off",
          
          "statusUrl": "http://local_esp_ip_address_goes_here/api/status"
        }   
    ]
}
```
