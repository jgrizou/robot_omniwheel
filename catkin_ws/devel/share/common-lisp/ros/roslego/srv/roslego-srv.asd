
(cl:in-package :asdf)

(defsystem "roslego-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "battery_voltage" :depends-on ("_package_battery_voltage"))
    (:file "_package_battery_voltage" :depends-on ("_package"))
  ))