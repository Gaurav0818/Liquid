workspace "Liquid"
    architecture "x64"

    configurations
    {
      "Debug",
      "Release",
      "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to root folder {solution directory}
IncludeDir = {}
IncludeDir["GLFW"] = "Liquid/vendor/GLFW/include"

include "Liquid/vendor/GLFW"

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
        "%{IncludeDir.GLFW}"
	}

    links
    {
        "GLFW"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

        defines
		{
            "LQD_PLATFORM_WINDOWS",
            "LQD_BUILD_DLL"
        }

        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

    filter "configurations:Debug"
        defines "LQD_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LQD_RELEASE"
        optimize  "On"

    filter "configurations:Dist"
        defines "LQD_DIST"
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
        symbols "On"

    filter "configurations:Release"
        defines "LQD_RELEASE"
        optimize  "On"

    filter "configurations:Dist"
        defines "LQD_DIST"
        optimize  "On"


