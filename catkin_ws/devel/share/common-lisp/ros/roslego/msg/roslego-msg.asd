
(cl:in-package :asdf)

(defsystem "roslego-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ahrs" :depends-on ("_package_ahrs"))
    (:file "_package_ahrs" :depends-on ("_package"))
    (:file "motor_action" :depends-on ("_package_motor_action"))
    (:file "_package_motor_action" :depends-on ("_package"))
  ))