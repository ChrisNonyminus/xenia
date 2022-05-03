project_root = "../../.."
include(project_root.."/tools/build")

group("src")
project("xenia-kernel")
  uuid("ae185c4a-1c4f-4503-9892-328e549e871a")
  kind("StaticLib")
  language("C++")
  links({
    "aes_128",
    "fmt",
    "xenia-apu",
    "xenia-base",
    "xenia-cpu",
    "xenia-hid",
    "xenia-vfs",
  })
  defines({
  })
  recursive_platform_files()
  files({
    "debug_visualizers.natvis",
  })

  -- TODO: This is temporary until we get a proper premake file going for opencv.
  filter("platforms:Windows")
    includedirs({
      "../../../third_party/opencv-build/win32/include"
    })
    libdirs({
      "../../../third_party/opencv-build/win32/x64/vc15/lib"
    })
    links({
      "opencv_world455",
    })
