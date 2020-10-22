Pod::Spec.new do |s|
  s.name         = "JMSmartBluetooth"
  s.version      = "1.0.3"
  s.summary      = "JMSmartBluetooth."

  s.description  = <<-DESC
  JMSmartBluetooth.
                   DESC

  s.homepage     = "http://10.0.10.85/app/ios/JMSmartBluetooth"
  s.license      = { :type => "Apache License 2.0", :file => "LICENSE" }
  s.author       = { "lzj<lizhijian_21@163.com>" => "lizhijian_21@163.com" }
  s.platform     = :ios, "9.0"
  s.requires_arc = true
  s.swift_version = '5.0'

  s.frameworks = ["CoreBluetooth"]
  
  #以framework方式发布
  s.source       = { :git => "https://github.com/JimiPlatform/JMSmartBluetooth.git", :tag => "#{s.version}" }
  s.ios.vendored_framework = 'JMSmartBluetooth.framework'

end

#发布命令
#pod trunk push JMSmartBluetooth.podspec --verbose --allow-warnings

