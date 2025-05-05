#pragma once
#include "Resource.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <vector>
#include <memory>



namespace myengine
{
	struct Sound : Resource
	{
		
		void onLoad();
		void load_audio(const std::string& _path, std::vector<unsigned char>& _buffer,
			ALenum& _format, ALsizei& _freq);
		
	private:
		ALuint id;
		ALuint sourceID;
		
		ALuint Sound::GetSource() { return sourceID; };

		std::shared_ptr<Sound> m_sound;
	};
}