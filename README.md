# ofxNVDA

An openFrameworks addon to control [the NVDA screen reader](https://www.nvaccess.org/).

## Dependencies

The addon has no dependencies, but to be useful the [NVDA software (free download)](https://www.nvaccess.org/download/) should be installed and running.

NVDA requires a Windows PC.

## How to Use

- include the addon using oF Project Generator
- add `#include "ofxNVDA.h"` to your code
- call `ofxNVDA::speakText( "your text" );`
- if NVDA is running, you should hear your text

## More Info

All available functions are in the `ofxNVDA` namespace:

```c++
// check if NVDA is running
bool ofxNVDA::isNVDARunning();

// make NVDA speak text
// (returns false on error)
bool ofxNVDA::speakText( const std::string& str );

// stop NVDA speaking
// (returns false on error)
bool ofxNVDA::cancelSpeech();

// produce a braille message (if using a braille display)
// (returns false on error)
bool ofxNVDA::brailleMessage( const std::string& str );
```

See the included example project for a demonstration.





