# MQTT (Message Quering Telemetry Transport) 
- It is a lightweight messaging protocol.  
- It is essentially designed for environment characterized by resource-constrained devices, limited bandwidth, high latency...
- It is communly used in IOT applications.  

## Publish-Subscribe Model:
- **Publisher** : An entity that sends messages on specific topics.  
- **Subscriber** : An entity that receives messages on specific topics.  
- **Broker** : An intermediate server between publishers and subscribers.  

## Topics :
- Messages in MQTT are published to topics, (message channels). 

## Lightweight :  
- MQTT is designed to be lightweight and efficient.  

# Mosquitto 
- Mosquitto is an open-source mqtt broker
## mosquitto_pub
`mosquitto_pub [-h host] [-p port] [-u username] [-P password] [-t topic] [-m message] [-q qos]`  
Options:
- `-h host`: Specify the hostname or IP address of the MQTT broker (default is localhost).  
- `-p port`: Specify the port number of the MQTT broker (default is 1883).
- `-u username`: Specify the username for authenticating with the MQTT broker.
- `-P password`: Specify the password for authenticating with the MQTT broker.
- `-t topic`: Specify the MQTT topic to which the message will be published.
- `-m message`: Specify the message payload to be published.
- `-q qos`: Specify the Quality of Service level for message delivery (0, 1, or 2).

## mosquitto_sub
`mosquitto_sub [-h host] [-p port] [-u username] [-P password] [-t topic] [-q qos]`
