#include <sdk.hpp>
#include <iostream>
#include "Server/Components/CustomModels/custommodels.hpp"

#include "api.hpp"
#include "Gomponent.hpp"

#ifdef __cplusplus
extern "C"
{
#endif

	GOMPONENT_EXPORT unsigned char customModel_add(uint8_t type, int32_t id, int32_t baseId, String dffName, String txdName, int32_t virtualWorld, uint8_t timeOn, uint8_t timeOff)
	{
		auto gamemode = Gomponent::Get()->getGamemode();
		ICustomModelsComponent* models = gamemode->models;

		if (models)
		{
			return models->addCustomModel(type, id, baseId, dffName, txdName, virtualWorld, timeOn, timeOff) ? 1 : 0;
		}

		return 0;
	}

	GOMPONENT_EXPORT String customModel_getNameFromCheckSum(uint32_t crc)
	{
		auto gamemode = Gomponent::Get()->getGamemode();
		ICustomModelsComponent* models = gamemode->models;

		if (models)
		{
			StringView nameView models->getModelNameFromChecksum(crc);
			return {nameView.buf, nameView.length};
		}

		return {NULL, 0};
	}

	GOMPONENT_EXPORT unsigned char customModel_getPath(uint32_t modelId, String* dffPath, String* txdPath)
	{
		auto gamemode = Gomponent::Get()->getGamemode();
		ICustomModelsComponent* models = gamemode->models;

		if (!models)
		{
			return 0;
		}

		StringView dffPathView {};
		StringView txdPathView {};

		bool status = models->getCustomModelPath(modelId, dffPathView, txtPathView);

		*dffPath = { dffPathView.data(), dffPathView.length() };
		*txdPath = { txdPathView.data(), txdPathView.length() };

		return status ? 1 : 0;
	}

#ifdef __cplusplus
}
#endif
