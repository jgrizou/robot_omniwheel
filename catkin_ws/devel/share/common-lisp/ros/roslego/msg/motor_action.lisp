; Auto-generated. Do not edit!


(cl:in-package roslego-msg)


;//! \htmlinclude motor_action.msg.html

(cl:defclass <motor_action> (roslisp-msg-protocol:ros-message)
  ((motor_id
    :reader motor_id
    :initarg :motor_id
    :type cl:fixnum
    :initform 0)
   (option
    :reader option
    :initarg :option
    :type cl:fixnum
    :initform 0)
   (value
    :reader value
    :initarg :value
    :type cl:integer
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:fixnum
    :initform 0)
   (direction
    :reader direction
    :initarg :direction
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass motor_action (<motor_action>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <motor_action>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'motor_action)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roslego-msg:<motor_action> is deprecated: use roslego-msg:motor_action instead.")))

(cl:ensure-generic-function 'motor_id-val :lambda-list '(m))
(cl:defmethod motor_id-val ((m <motor_action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:motor_id-val is deprecated.  Use roslego-msg:motor_id instead.")
  (motor_id m))

(cl:ensure-generic-function 'option-val :lambda-list '(m))
(cl:defmethod option-val ((m <motor_action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:option-val is deprecated.  Use roslego-msg:option instead.")
  (option m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <motor_action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:value-val is deprecated.  Use roslego-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <motor_action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:speed-val is deprecated.  Use roslego-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <motor_action>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:direction-val is deprecated.  Use roslego-msg:direction instead.")
  (direction m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <motor_action>) ostream)
  "Serializes a message object of type '<motor_action>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'option)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'speed)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'direction) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <motor_action>) istream)
  "Deserializes a message object of type '<motor_action>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'option)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'value)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'speed)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'direction) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<motor_action>)))
  "Returns string type for a message object of type '<motor_action>"
  "roslego/motor_action")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'motor_action)))
  "Returns string type for a message object of type 'motor_action"
  "roslego/motor_action")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<motor_action>)))
  "Returns md5sum for a message object of type '<motor_action>"
  "a9cd8a8245ed8f77485f23b78d324966")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'motor_action)))
  "Returns md5sum for a message object of type 'motor_action"
  "a9cd8a8245ed8f77485f23b78d324966")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<motor_action>)))
  "Returns full string definition for message of type '<motor_action>"
  (cl:format cl:nil "uint8 motor_id~%uint8 option~%uint32 value~%uint8 speed~%bool direction~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'motor_action)))
  "Returns full string definition for message of type 'motor_action"
  (cl:format cl:nil "uint8 motor_id~%uint8 option~%uint32 value~%uint8 speed~%bool direction~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <motor_action>))
  (cl:+ 0
     1
     1
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <motor_action>))
  "Converts a ROS message object to a list"
  (cl:list 'motor_action
    (cl:cons ':motor_id (motor_id msg))
    (cl:cons ':option (option msg))
    (cl:cons ':value (value msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':direction (direction msg))
))
