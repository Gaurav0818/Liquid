workspace "Liquid"
    architecture "x64"

    configurations
    {
      "Debug",
      "Release",
      "Dist"
    }
    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder {solution directory}
IncludeDir = {}
IncludeDir["GLFW"] = "Liquid/vendor/GLFW/include"
IncludeDir["Glad"] = "Liquid/vendor/Glad/include"

include "Liquid/vendor/GLFW"
include "Liquid/vendor/Glad"

project "Liquid"
    location "Liquid"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

    pchheader "pch.h"
	pchsource "Liquid/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.GLFW}"
	}

    links
    {
        "Glad",
        "GLFW"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

        defines
		{
            "LQD_PLATFORM_WINDOWS",
            "LQD_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

    filter "configurations:Debug"
        defines "LQD_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "LQD_RELEASE"
        buildoptions "/MD"
        optimize  "On"

    filter "configurations:Dist"
        defines "LQD_DIST"
        buildoptions "/MD"
        optimize  "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Liquid/vendor/spdlog/include",
		"Liquid/src"
	}

    links { "Liquid" }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

        defines "LQD_PLATFORM_WINDOWS"

    filter "configurations:Debug"
        defines "LQD_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "LQD_RELEASE"
        buildoptions "/MD"
        optimize  "On"

    filter "configurations:Dist"
        defines "LQD_DIST"
        buildoptions "/MD"
        optimize  "On"


