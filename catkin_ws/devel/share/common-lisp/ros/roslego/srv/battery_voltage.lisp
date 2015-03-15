; Auto-generated. Do not edit!


(cl:in-package roslego-srv)


;//! \htmlinclude battery_voltage-request.msg.html

(cl:defclass <battery_voltage-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass battery_voltage-request (<battery_voltage-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <battery_voltage-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'battery_voltage-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roslego-srv:<battery_voltage-request> is deprecated: use roslego-srv:battery_voltage-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <battery_voltage-request>) ostream)
  "Serializes a message object of type '<battery_voltage-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <battery_voltage-request>) istream)
  "Deserializes a message object of type '<battery_voltage-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<battery_voltage-request>)))
  "Returns string type for a service object of type '<battery_voltage-request>"
  "roslego/battery_voltageRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'battery_voltage-request)))
  "Returns string type for a service object of type 'battery_voltage-request"
  "roslego/battery_voltageRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<battery_voltage-request>)))
  "Returns md5sum for a message object of type '<battery_voltage-request>"
  "78b08b1408586613a7b39667400173e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'battery_voltage-request)))
  "Returns md5sum for a message object of type 'battery_voltage-request"
  "78b08b1408586613a7b39667400173e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<battery_voltage-request>)))
  "Returns full string definition for message of type '<battery_voltage-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'battery_voltage-request)))
  "Returns full string definition for message of type 'battery_voltage-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <battery_voltage-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <battery_voltage-request>))
  "Converts a ROS message object to a list"
  (cl:list 'battery_voltage-request
))
;//! \htmlinclude battery_voltage-response.msg.html

(cl:defclass <battery_voltage-response> (roslisp-msg-protocol:ros-message)
  ((millivolts
    :reader millivolts
    :initarg :millivolts
    :type cl:fixnum
    :initform 0))
)

(cl:defclass battery_voltage-response (<battery_voltage-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <battery_voltage-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'battery_voltage-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name roslego-srv:<battery_voltage-response> is deprecated: use roslego-srv:battery_voltage-response instead.")))

(cl:ensure-generic-function 'millivolts-val :lambda-list '(m))
(cl:defmethod millivolts-val ((m <battery_voltage-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader roslego-srv:millivolts-val is deprecated.  Use roslego-srv:millivolts instead.")
  (millivolts m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <battery_voltage-response>) ostream)
  "Serializes a message object of type '<battery_voltage-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'millivolts)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'millivolts)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <battery_voltage-response>) istream)
  "Deserializes a message object of type '<battery_voltage-response>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'millivolts)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'millivolts)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<battery_voltage-response>)))
  "Returns string type for a service object of type '<battery_voltage-response>"
  "roslego/battery_voltageResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'battery_voltage-response)))
  "Returns string type for a service object of type 'battery_voltage-response"
  "roslego/battery_voltageResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<battery_voltage-response>)))
  "Returns md5sum for a message object of type '<battery_voltage-response>"
  "78b08b1408586613a7b39667400173e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'battery_voltage-response)))
  "Returns md5sum for a message object of type 'battery_voltage-response"
  "78b08b1408586613a7b39667400173e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<battery_voltage-response>)))
  "Returns full string definition for message of type '<battery_voltage-response>"
  (cl:format cl:nil "uint16 millivolts~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'battery_voltage-response)))
  "Returns full string definition for message of type 'battery_voltage-response"
  (cl:format cl:nil "uint16 millivolts~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <battery_voltage-response>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <battery_voltage-response>))
  "Converts a ROS message object to a list"
  (cl:list 'battery_voltage-response
    (cl:cons ':millivolts (millivolts msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'battery_voltage)))
  'battery_voltage-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'battery_voltage)))
  'battery_voltage-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'battery_voltage)))
  "Returns string type for a service object of type '<battery_voltage>"
  "roslego/battery_voltage")