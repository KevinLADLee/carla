// Copyright (c) 2021 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/MsgPack.h"

#ifdef LIBCARLA_INCLUDED_FROM_UE4
#  include "Carla/Vehicle/AckermannController.h"
#endif // LIBCARLA_INCLUDED_FROM_UE4

namespace carla {
namespace rpc {

class AckermannControlInfo {
 public:

  AckermannControlInfo() = default;

  AckermannControlInfo(float target_steer,
                       float target_steer_speed,
                       float target_speed,
                       float target_acceleration,
//                       float target_jerk,
                       float current_steer,
                       float current_speed,
                       float current_acceleration,
                       float speed_pid_delta,
                       float speed_pid_target,
                       float accel_pid_delta,
                       float accel_pid_target,
                       float output_steer,
                       float output_throttle,
                       float output_brake)
      : target_steer(target_steer),
        target_steer_speed(target_steer_speed),
        target_speed(target_speed),
        target_acceleration(target_acceleration),
//        target_jerk(target_jerk),
        current_steer(current_steer),
        current_speed(current_speed),
        current_acceleration(current_acceleration),
        speed_pid_delta(speed_pid_delta),
        speed_pid_target(speed_pid_target),
        accel_pid_delta(accel_pid_delta),
        accel_pid_target(accel_pid_target),
        output_steer(output_steer),
        output_throttle(output_throttle),
        output_brake(output_brake) {}

  float target_steer = 0.0f;
  float target_steer_speed = 0.0f;
  float target_speed = 0.0f;
  float target_acceleration = 0.0f;
  float target_jerk = 0.0f;

  float current_steer = 0.0f;
  float current_speed = 0.0f;
  float current_acceleration = 0.0f;

  float speed_pid_delta = 0.0f;
  float speed_pid_target = 0.0f;
  float accel_pid_delta = 0.0f;
  float accel_pid_target = 0.0f;

  float output_steer = 0.0f;
  float output_throttle = 0.0f;
  float output_brake = 0.0f;


#ifdef LIBCARLA_INCLUDED_FROM_UE4

  AckermannControlInfo(const FAckermannControlInfo &ControlInfo)
      : target_steer(ControlInfo.TargetSteer ),
        target_steer_speed(ControlInfo.TargetSteerSpeed),
        target_speed(ControlInfo.TargetSpeed),
        target_acceleration(ControlInfo.TargetAcceleration),
        target_jerk(ControlInfo.TargetJerk),
        current_steer(ControlInfo.CurrentSteer),
        current_speed(ControlInfo.CurrentSpeed),
        current_acceleration(ControlInfo.CurrentAcceleration),
        speed_pid_delta(ControlInfo.SpeedPidDelta),
        speed_pid_target(ControlInfo.SpeedPidTarget),
        accel_pid_delta(ControlInfo.AccelPidDelta),
        accel_pid_target(ControlInfo.AccelPidTarget),
        output_steer(ControlInfo.OutputSteer),
        output_throttle(ControlInfo.OutputThrottle),
        output_brake(ControlInfo.OutputBrake) {}

    operator FAckermannControlInfo() const {
      FAckermannControlInfo ControlInfo;
      ControlInfo.TargetSteer = target_steer;
      ControlInfo.TargetSteerSpeed = target_steer_speed;
      ControlInfo.TargetSpeed = target_speed;
      ControlInfo.TargetAcceleration = target_acceleration;
      ControlInfo.TargetJerk = target_jerk;

      ControlInfo.CurrentSteer = current_steer;
      ControlInfo.CurrentSpeed = current_speed;
      ControlInfo.CurrentAcceleration = current_acceleration;

      ControlInfo.SpeedPidDelta = speed_pid_delta;
      ControlInfo.SpeedPidTarget = speed_pid_target;
      ControlInfo.AccelPidDelta = accel_pid_delta;
      ControlInfo.AccelPidTarget = accel_pid_target;

      ControlInfo.OutputBrake = output_brake;
      ControlInfo.OutputThrottle = output_throttle;
      ControlInfo.OutputSteer = output_steer;

      return ControlInfo;
    }

#endif // LIBCARLA_INCLUDED_FROM_UE4

  bool operator!=(const AckermannControlInfo &rhs) const {
    return target_steer != rhs.target_steer ||
        target_steer_speed != rhs.target_steer_speed ||
        target_speed != rhs.target_speed ||
        target_acceleration != rhs.target_acceleration ||
        target_jerk != rhs.target_jerk ||
        current_steer != rhs.current_steer ||
        current_speed != rhs.current_speed ||
        current_acceleration != rhs.current_acceleration ||
        speed_pid_delta != rhs.speed_pid_delta ||
        speed_pid_target != rhs.speed_pid_target ||
        accel_pid_delta != rhs.accel_pid_delta ||
        accel_pid_target != rhs.accel_pid_target ||
        output_steer != rhs.output_steer ||
        output_throttle != rhs.output_throttle ||
        output_brake != rhs.output_brake;
  }

  bool operator==(const AckermannControlInfo &rhs) const {
    return !(*this != rhs);
  }

  MSGPACK_DEFINE_ARRAY(
      target_steer,
      target_steer_speed,
      target_speed,
      target_acceleration,
//      target_jerk,

      current_steer,
      current_speed,
      current_acceleration,

      speed_pid_delta,
      speed_pid_target,
      accel_pid_delta,
      accel_pid_target,

      output_steer,
      output_throttle,
      output_brake
  );
};

} // namespace rpc
} // namespace carla
