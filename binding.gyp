{
	"targets": [
		{
			"target_name":"haiku",
			"includes": [
				"auto.gypi"
			],
			"sources": [
				"src/bindings.cc"
			],
		"ldflags":[
		"-shared",
		"-o _haiku.so",
		"-L/boot/system/lib",
		"-lbe",
		"-ltracker"
		]

		},
	],
	"includes": [
		"auto-top.gypi"
	]
}
