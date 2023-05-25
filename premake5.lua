workspace "Liquid"
	architecture "x64"

	configurations
	{
		"Debug",
		"Rekease",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Liquid"
	location "Liquid"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vender/spdlog/include"
	}

	filter "system.windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines	{ "LQD_PLATFORM_WINDOWS", "LQD_BUILD_DLL" }

		postbuildcommands { 'copy /Y "%{wks.name}\\bin\\' .. outputdir .. '\\Liquid\\Liquid.dll", "%{wks.name}\\bin\\' .. outputdir .. '\\Sandbox"' }


	filter "configurations:Debug"
		defines "LQD_DEBUG"
		symbols "On"	
		
	filter "configurations:Release"
		defines "LQD_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LQD_DIST"
		symbols "On"


project	"Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

	includedirs { "Liquid/vender/spdlog/include",  "Liquid/src" }

	links { "Liquid" }

	filter "system.windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines { "LQD_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "LQD_DEBUG"
		symbols "On"	
		
	filter "configurations:Release"
		defines "LQD_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "LQD_DIST"
		symbols "On"
	