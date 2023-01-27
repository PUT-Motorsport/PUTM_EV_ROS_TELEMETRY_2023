;; Auto-generated. Do not edit!


(when (boundp 'ROS_Telemetry::Apps_main)
  (if (not (find-package "ROS_TELEMETRY"))
    (make-package "ROS_TELEMETRY"))
  (shadow 'Apps_main (find-package "ROS_TELEMETRY")))
(unless (find-package "ROS_TELEMETRY::APPS_MAIN")
  (make-package "ROS_TELEMETRY::APPS_MAIN"))

(in-package "ROS")
;;//! \htmlinclude Apps_main.msg.html


(defclass ROS_Telemetry::Apps_main
  :super ros::object
  :slots (_pedal_position _counter _position_diff _device_state ))

(defmethod ROS_Telemetry::Apps_main
  (:init
   (&key
    ((:pedal_position __pedal_position) 0)
    ((:counter __counter) 0)
    ((:position_diff __position_diff) 0)
    ((:device_state __device_state) 0)
    )
   (send-super :init)
   (setq _pedal_position (round __pedal_position))
   (setq _counter (round __counter))
   (setq _position_diff (round __position_diff))
   (setq _device_state (round __device_state))
   self)
  (:pedal_position
   (&optional __pedal_position)
   (if __pedal_position (setq _pedal_position __pedal_position)) _pedal_position)
  (:counter
   (&optional __counter)
   (if __counter (setq _counter __counter)) _counter)
  (:position_diff
   (&optional __position_diff)
   (if __position_diff (setq _position_diff __position_diff)) _position_diff)
  (:device_state
   (&optional __device_state)
   (if __device_state (setq _device_state __device_state)) _device_state)
  (:serialization-length
   ()
   (+
    ;; uint16 _pedal_position
    2
    ;; uint8 _counter
    1
    ;; int8 _position_diff
    1
    ;; uint8 _device_state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _pedal_position
       (write-word _pedal_position s)
     ;; uint8 _counter
       (write-byte _counter s)
     ;; int8 _position_diff
       (write-byte _position_diff s)
     ;; uint8 _device_state
       (write-byte _device_state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _pedal_position
     (setq _pedal_position (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _counter
     (setq _counter (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int8 _position_diff
     (setq _position_diff (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _position_diff 127) (setq _position_diff (- _position_diff 256)))
   ;; uint8 _device_state
     (setq _device_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ROS_Telemetry::Apps_main :md5sum-) "4a5de748b20de5195675b828a1b04fa1")
(setf (get ROS_Telemetry::Apps_main :datatype-) "ROS_Telemetry/Apps_main")
(setf (get ROS_Telemetry::Apps_main :definition-)
      "uint16 pedal_position
uint8 counter
int8 position_diff
uint8 device_state
")



(provide :ROS_Telemetry/Apps_main "4a5de748b20de5195675b828a1b04fa1")


