workspace "Liquid"
	architecture "x64"
	startproject "SampleProject"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Liquid"
	location "Liquid"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("obj/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines 
		{
			"LQD_PLATFORM_WINDOWS",
			"LQD_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/SampleProject")
		}

	filter "configurations:Debug"
		defines "LQD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LQD_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LQD_DIST"
		symbols "On"


project "SampleProject"
	location "SampleProject"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("obj/" .. outputDir .. "/%{prj.name}")

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

	links
	{
		"Liquid"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines 
		{
			"LQD_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LQD_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "LQD_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LQD_DIST"
		symbols "On"