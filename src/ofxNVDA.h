#pragma once
#include <string>

#include "nvdaController.h"

namespace ofxNVDA {

// --------------- singleton interface ---------------
class Controller
{
public:
	static Controller& get()
	{  // instance
		static Controller self;
		return self;
	}

	bool isNVDARunning() const
	{
		return nvdaController_testIfRunning() == 0;
	}

	bool speakText( const std::string& str )
	{
		std::wstring wStr( str.begin(), str.end() );
		return nvdaController_speakText( wStr.c_str() ) == 0;
	}

	bool cancelSpeech()
	{
		return nvdaController_cancelSpeech() == 0;
	}

	bool brailleMessage( const std::string& str )
	{
		std::wstring wStr( str.begin(), str.end() );
		return nvdaController_brailleMessage( wStr.c_str() ) == 0;
	}

protected:
	Controller() {}
};

// --------------- global interface ---------------

inline bool isNVDARunning()
{
	return Controller::get().isNVDARunning();
};

inline bool speakText( const std::string& str )
{
	return Controller::get().speakText( str );
}

inline bool cancelSpeech()
{
	return Controller::get().cancelSpeech();
}

inline bool brailleMessage( const std::string& str )
{
	return Controller::get().brailleMessage( str );
}

};  // namespace ofxNVDA