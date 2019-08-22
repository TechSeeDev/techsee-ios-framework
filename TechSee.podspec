
Pod::Spec.new do |s|
  s.name         = 'TechSee'
  s.version      = '1.0.5'
  s.summary      = 'TechSeeLiveFramework framework'
  s.author       = { 'Shlomi Sharon' => 'shlomis@techsee.me' }
  s.homepage     = 'https://techsee.me'
  s.license      = 'MIT'

  s.platform     = :ios, '10'
s.source       = { :git => 'https://github.com/TechSeeDev/techsee-ios-framework.git', :tag => '1.0.5' }

s.ios.deployment_target  = '10.0'
#s.resources = 'TechSeeLiveFramework.framework/**/**/*.{png,json,jpeg,jpg,storyboard,nib,xcassets}'
s.public_header_files = 'TechSeeLiveFramework.framework/TechSee.{h}'

s.static_framework = true

s.vendored_frameworks = 'TechSeeLiveFramework.framework'

s.frameworks = 'Foundation',
        'AVFoundation',
        'AudioToolbox',
        'CoreFoundation',
        'CoreGraphics',
        'CoreMedia',
        'CoreTelephony',
        'CoreVideo',
        'GLKit',
        'OpenGLES',
        'QuartzCore',
        'SystemConfiguration',
        'UIKit',
        'VideoToolbox'

    s.libraries = 'c++'

    #UI
    s.dependency 'MBProgressHUD', '~> 1.1.0'

    #Data
    s.dependency 'DeviceUtil', '~> 4.0.2'

    #Network
    s.dependency 'VPSocketIO'
    s.dependency 'AFNetworking'

    #WebRTC
    s.dependency 'TechSeeWebRTC', '= 1.0'
    s.dependency 'OpenTok', '= 2.15.2'

    #Animation
    s.dependency 'lottie-ios', '= 2.5.3'

    #Logging
    s.dependency 'CocoaLumberjack'
end
