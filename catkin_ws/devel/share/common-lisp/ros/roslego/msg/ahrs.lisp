; Auto-generated. Do not edit!


(cl:in-package roslego-msg)


;//! \htmlinclude ahrs.msg.html

(cl:defclass <ahrs> (roslisp-msg-protocol:ros-message)
  ((yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0)
   (roll
    :reader roll
    :initarg :roll
    :type cl:float
    :initform 0.0))
)

(cl:defclass ahrs (<ahrs>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ahrs>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ahrs)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roslego-msg:<ahrs> is deprecated: use roslego-msg:ahrs instead.")))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <ahrs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:yaw-val is deprecated.  Use roslego-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <ahrs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:pitch-val is deprecated.  Use roslego-msg:pitch instead.")
  (pitch m))

(cl:ensure-generic-function 'roll-val :lambda-list '(m))
(cl:defmethod roll-val ((m <ahrs>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-msg:roll-val is deprecated.  Use roslego-msg:roll instead.")
  (roll m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ahrs>) ostream)
  "Serializes a message object of type '<ahrs>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'roll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ahrs>) istream)
  "Deserializes a message object of type '<ahrs>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'roll) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ahrs>)))
  "Returns string type for a message object of type '<ahrs>"
  "roslego/ahrs")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ahrs)))
  "Returns string type for a message object of type 'ahrs"
  "roslego/ahrs")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ahrs>)))
  "Returns md5sum for a message object of type '<ahrs>"
  "5b83d17121a77a6856144c74d9af68ba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ahrs)))
  "Returns md5sum for a message object of type 'ahrs"
  "5b83d17121a77a6856144c74d9af68ba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ahrs>)))
  "Returns full string definition for message of type '<ahrs>"
  (cl:format cl:nil "float32 yaw~%float32 pitch~%float32 roll~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ahrs)))
  "Returns full string definition for message of type 'ahrs"
  (cl:format cl:nil "float32 yaw~%float32 pitch~%float32 roll~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ahrs>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ahrs>))
  "Converts a ROS message object to a list"
  (cl:list 'ahrs
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':pitch (pitch msg))
    (cl:cons ':roll (roll msg))
))
