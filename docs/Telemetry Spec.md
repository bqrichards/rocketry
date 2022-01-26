# Telemetry Spec
## Version 1.0
### Mission start
- Event: `MS`
- Format: `MS[timestamp]`
	- `timestamp` is the milliseconds since the beginning of the mission. 

### Sensor data
- Event: `SD`
- Format: `SD[timestamp,imu_x,imu_y,imu_z,quat_x,quat_y,quat_z,quat_w,pressure,altitude,temperature]`
	- Each sensor datapoint will have 2 decimal accuracy

### Sensor status
- Event: `SS`
- Format: `SS[timestamp,name,status]`
	- `name`
		- `i` - imu
		- `b` - bmp
	- `status`
		- `u` - uninitialized
		- `p` - pending
		- `s` - success
		- `f` - fail


### Ground altitude calibration
- Event: `GA`
- Format: `GA[timestamp,calibrating,ground_altitude]`
	- `calibrating`
		- `t` - true
		- `f` - false