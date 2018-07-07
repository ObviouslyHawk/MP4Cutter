#include "SingletonSettings.h"

SingletonSettings& SingletonSettings::getInstance() {
	static SingletonSettings instance;
	return instance;
}

void SingletonSettings::setBeginTime(uint32_t time) {
	m_beginTime = time;
}

void SingletonSettings::setEndTime(uint32_t time) {
	m_endTime = time;
}

void SingletonSettings::setPeriodTime(uint32_t begTime, uint32_t endTime) {
	m_beginTime = begTime;
	m_endTime = endTime;
}

uint32_t SingletonSettings::getBeginTime() {
	return m_beginTime;
}

uint32_t SingletonSettings::getEndTime() {
	return m_endTime;
}

uint32_t SingletonSettings::getScaledBeginTimeVideo() {
	return m_scaledBeginTimeVideo;
}

uint32_t SingletonSettings::getScaledEndTimeVideo() {
	return m_scaledEndTimeVideo;
}

uint32_t SingletonSettings::getScaledBeginTimeAudio() {
	return m_scaledBeginTimeAudio;
}

uint32_t SingletonSettings::getScaledEndTimeAudio() {
	return m_scaledEndTimeAudio;
}

void SingletonSettings::setTimeScaleAudio(uint32_t &timeScale) {
	pm_timeScaleAudio = &timeScale;
	m_scaledBeginTimeAudio = *pm_timeScaleAudio * m_beginTime;
	m_scaledEndTimeAudio = *pm_timeScaleAudio * m_endTime;
}

void SingletonSettings::setTimeScaleVideo(uint32_t &timeScale) {
	pm_timeScaleVideo = &timeScale;
	m_scaledBeginTimeVideo = *pm_timeScaleVideo * m_beginTime;
	m_scaledEndTimeVideo = *pm_timeScaleVideo * m_endTime;
}

uint32_t SingletonSettings::getTimeScaleAudio() {
	return *pm_timeScaleAudio;
}

uint32_t SingletonSettings::getTimeScaleVideo() {
	return *pm_timeScaleVideo;
}

void SingletonSettings::setDeltaAudio(uint32_t delta) {
	m_deltaAudio = delta;
}

void SingletonSettings::setDeltaVideo(uint32_t delta) {
	m_deltaVideo = delta;
}

uint32_t SingletonSettings::getDeltaAudio() {
	return m_deltaAudio;	
}

uint32_t SingletonSettings::getDeltaVideo() {
	return m_deltaVideo;
}

void SingletonSettings::setBeginOffsetAudio(uint32_t offset) {
	m_beginOffsetAudio = offset;
}

void SingletonSettings::setEndOffsetAudio(uint32_t offset) {
	m_endOffsetAudio = offset;
}

void SingletonSettings::setBeginOffsetVideo(uint32_t offset) {
	m_beginOffsetVideo = offset;
}
void SingletonSettings::setEndOffsetVideo(uint32_t offset) {
	m_endOffsetVideo = offset;
}

uint32_t SingletonSettings::getBeginOffsetAudio() {
	return m_beginOffsetAudio;
}

uint32_t SingletonSettings::getEndOffsetAudio() {
	return m_endOffsetAudio;
}

uint32_t SingletonSettings::getBeginOffsetVideo() {
	return m_beginOffsetVideo;
}

uint32_t SingletonSettings::getEndOffsetVideo() {
	return m_endOffsetVideo;
}

void SingletonSettings::setArrayChunkOffsetAudio(std::vector<uint32_t> &arrayChunkOffset) {
	pm_chunkOffsetAudio = &arrayChunkOffset;
}

void SingletonSettings::setArrayChunkOffsetVideo(std::vector<uint32_t> &arrayChunkOffset) {
	pm_chunkOffsetVideo = &arrayChunkOffset;
}

std::vector<uint32_t> SingletonSettings::getArrayChunkOffsetAudio() {
	return *pm_chunkOffsetAudio;
}

std::vector<uint32_t> SingletonSettings::getArrayChunkOffsetVideo() {
	return *pm_chunkOffsetVideo;
}