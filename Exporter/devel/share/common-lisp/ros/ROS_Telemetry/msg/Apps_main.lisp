; Auto-generated. Do not edit!


(cl:in-package ROS_Telemetry-msg)


;//! \htmlinclude Apps_main.msg.html

(cl:defclass <Apps_main> (roslisp-msg-protocol:ros-message)
  ((pedal_position
    :reader pedal_position
    :initarg :pedal_position
    :type cl:fixnum
    :initform 0)
   (counter
    :reader counter
    :initarg :counter
    :type cl:fixnum
    :initform 0)
   (position_diff
    :reader position_diff
    :initarg :position_diff
    :type cl:fixnum
    :initform 0)
   (device_state
    :reader device_state
    :initarg :device_state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass Apps_main (<Apps_main>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Apps_main>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Apps_main)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ROS_Telemetry-msg:<Apps_main> is deprecated: use ROS_Telemetry-msg:Apps_main instead.")))

(cl:ensure-generic-function 'pedal_position-val :lambda-list '(m))
(cl:defmethod pedal_position-val ((m <Apps_main>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ROS_Telemetry-msg:pedal_position-val is deprecated.  Use ROS_Telemetry-msg:pedal_position instead.")
  (pedal_position m))

(cl:ensure-generic-function 'counter-val :lambda-list '(m))
(cl:defmethod counter-val ((m <Apps_main>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ROS_Telemetry-msg:counter-val is deprecated.  Use ROS_Telemetry-msg:counter instead.")
  (counter m))

(cl:ensure-generic-function 'position_diff-val :lambda-list '(m))
(cl:defmethod position_diff-val ((m <Apps_main>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ROS_Telemetry-msg:position_diff-val is deprecated.  Use ROS_Telemetry-msg:position_diff instead.")
  (position_diff m))

(cl:ensure-generic-function 'device_state-val :lambda-list '(m))
(cl:defmethod device_state-val ((m <Apps_main>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ROS_Telemetry-msg:device_state-val is deprecated.  Use ROS_Telemetry-msg:device_state instead.")
  (device_state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Apps_main>) ostream)
  "Serializes a message object of type '<Apps_main>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pedal_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pedal_position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'counter)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'position_diff)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'device_state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Apps_main>) istream)
  "Deserializes a message object of type '<Apps_main>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'pedal_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'pedal_position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'counter)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position_diff) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'device_state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Apps_main>)))
  "Returns string type for a message object of type '<Apps_main>"
  "ROS_Telemetry/Apps_main")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Apps_main)))
  "Returns string type for a message object of type 'Apps_main"
  "ROS_Telemetry/Apps_main")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Apps_main>)))
  "Returns md5sum for a message object of type '<Apps_main>"
  "4a5de748b20de5195675b828a1b04fa1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Apps_main)))
  "Returns md5sum for a message object of type 'Apps_main"
  "4a5de748b20de5195675b828a1b04fa1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Apps_main>)))
  "Returns full string definition for message of type '<Apps_main>"
  (cl:format cl:nil "uint16 pedal_position~%uint8 counter~%int8 position_diff~%uint8 device_state~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Apps_main)))
  "Returns full string definition for message of type 'Apps_main"
  (cl:format cl:nil "uint16 pedal_position~%uint8 counter~%int8 position_diff~%uint8 device_state~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Apps_main>))
  (cl:+ 0
     2
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Apps_main>))
  "Converts a ROS message object to a list"
  (cl:list 'Apps_main
    (cl:cons ':pedal_position (pedal_position msg))
    (cl:cons ':counter (counter msg))
    (cl:cons ':position_diff (position_diff msg))
    (cl:cons ':device_state (device_state msg))
))
