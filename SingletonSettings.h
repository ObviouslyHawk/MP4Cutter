#ifndef SINGLETONSETTINGS_H
#define SINGLETONSETTINGS_H

#include <iostream>

class SingletonSettings
{
private:
	SingletonSettings() {}
	SingletonSettings(const SingletonSettings&) {}
	SingletonSettings& operator=(SingletonSettings&) {}

	uint32_t m_beginTime{ 0 },
		m_endTime{ 0 },

		m_scaledBeginTimeVideo{ 0 },
		m_scaledEndTimeVideo{ 0 },
		*pm_timeScaleVideo{ nullptr },

		m_scaledBeginTimeAudio{ 0 },
		m_scaledEndTimeAudio{ 0 },
		*pm_timeScaleAudio{ nullptr },

		m_deltaAudio{ 0 },
		m_deltaVideo{ 0 };

public:
	static SingletonSettings& getInstance();

	void setDeltaAudio(uint32_t delta);
	void setDeltaVideo(uint32_t delta);

	uint32_t getDeltaAudio();
	uint32_t getDeltaVideo();

	void setBeginTime(uint32_t time);
	void setEndTime(uint32_t time);
	void setPeriodTime(uint32_t begTime, uint32_t endTime);

	void setTimeScaleAudio(const uint32_t &timeScale);
	void setTimeScaleVideo(const uint32_t &timeScale);

	uint32_t getBeginTime();
	uint32_t getEndTime();

	uint32_t getTimeScaleAudio();
	uint32_t getTimeScaleVideo();

	uint32_t getScaledBeginTimeVideo();
	uint32_t getScaledEndTimeVideo();

	uint32_t getScaledBeginTimeAudio();
	uint32_t getScaledEndTimeAudio();

};

#endif