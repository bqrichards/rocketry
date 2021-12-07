# Stage - Ground Idle
## Sensors
- [[IMU]]
## Event Loop
### Overview
The event loop is watching for liftoff.

### Criteria
1. Acceleration Z >= threshold
2. Has passed Criteria 1 for >= 200 milliseconds