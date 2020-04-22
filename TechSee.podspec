
Pod::Spec.new do |s|
  s.name         = 'TechSee'
  s.version      = '2.4.4'
  s.summary      = 'TechSee SDK'
  s.author       = { 'Shlomi Sharon' => 'shlomis@techsee.me' }
  s.homepage     = 'https://techsee.me'
  s.license      = { :type => 'Apache License, Version 2.0', :text => <<-LICENSE
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
LICENSE
}

s.platform     = :ios, '11'
s.source       = { :git => 'https://github.com/TechSeeDev/techsee-ios-framework.git', :tag => s.version }

s.ios.deployment_target  = '11.0'
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

    #WebRTC
    s.dependency 'TechSeeWebRTC', '= 1.1'
end
