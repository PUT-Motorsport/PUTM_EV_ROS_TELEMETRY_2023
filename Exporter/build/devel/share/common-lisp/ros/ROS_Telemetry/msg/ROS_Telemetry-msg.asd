
(cl:in-package :asdf)

(defsystem "ROS_Telemetry-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Apps_main" :depends-on ("_package_Apps_main"))
    (:file "_package_Apps_main" :depends-on ("_package"))
    (:file "WheelTemp_main" :depends-on ("_package_WheelTemp_main"))
    (:file "_package_WheelTemp_main" :depends-on ("_package"))
  ))