
(cl:in-package :asdf)

(defsystem "rover_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "WheelVelPower" :depends-on ("_package_WheelVelPower"))
    (:file "_package_WheelVelPower" :depends-on ("_package"))
    (:file "Power" :depends-on ("_package_Power"))
    (:file "_package_Power" :depends-on ("_package"))
    (:file "SC_task" :depends-on ("_package_SC_task"))
    (:file "_package_SC_task" :depends-on ("_package"))
    (:file "Battery_level" :depends-on ("_package_Battery_level"))
    (:file "_package_Battery_level" :depends-on ("_package"))
    (:file "digger" :depends-on ("_package_digger"))
    (:file "_package_digger" :depends-on ("_package"))
    (:file "Arm" :depends-on ("_package_Arm"))
    (:file "_package_Arm" :depends-on ("_package"))
    (:file "GripperMotion" :depends-on ("_package_GripperMotion"))
    (:file "_package_GripperMotion" :depends-on ("_package"))
    (:file "GPS" :depends-on ("_package_GPS"))
    (:file "_package_GPS" :depends-on ("_package"))
    (:file "ArmAngle" :depends-on ("_package_ArmAngle"))
    (:file "_package_ArmAngle" :depends-on ("_package"))
    (:file "Enc" :depends-on ("_package_Enc"))
    (:file "_package_Enc" :depends-on ("_package"))
    (:file "RouterAngle" :depends-on ("_package_RouterAngle"))
    (:file "_package_RouterAngle" :depends-on ("_package"))
    (:file "MPU" :depends-on ("_package_MPU"))
    (:file "_package_MPU" :depends-on ("_package"))
    (:file "CameraMotion" :depends-on ("_package_CameraMotion"))
    (:file "_package_CameraMotion" :depends-on ("_package"))
    (:file "WheelVelocity" :depends-on ("_package_WheelVelocity"))
    (:file "_package_WheelVelocity" :depends-on ("_package"))
  ))