# Telemetry Spec
## Version 1.0
### Sensor data
- Format: `SD[imu_x,imu_y,imu_z,quat_x,quat_y,quat_z,quat_w,pressure,altitude,temperature]`
- Each number will have 2 decimal accuracy

### Sensor status
- Format: `SS[name,status]`
- `name`
	- `i` - imu
	- `b` - bmp
- `status`
	- `u` - uninitialized
	- `p` - pending
	- `s` - success
	- `f` - fail


### Ground altitude calibration
- Format: `GA[calibrating,ground_altitude]`
- `calibrating`
	- `t` - true
	- `f` - false