#pragma once
#include "stdafx.h"
#include "EInputLayoutType.h"
#include "EShaderType.h"
#include "SVertex.h"
#include "SModel.h"
#include "CTexture2D.h"
#include "CShader.h"
#include "CGraphics.h"
#include "CSysWindow.h"

namespace dxfw
{
	class CTexture2D;
	class CShader;
	class CGraphics;
	class CSysWindow;

	typedef std::unordered_map<std::string, SModel>::iterator itrModels;
	typedef std::unordered_map<std::string, CTexture2D*>::iterator itrTextures;
	typedef std::unordered_map<std::string, CShader*>::iterator itrShaders;

	class CResourceManager
	{
	public:
		CResourceManager(CGraphics* pGraphics, CSysWindow* pSysWindow);
		~CResourceManager();

		SModel* LoadModel(const std::string& pFileName);
		void UnloadModel(SModel& model);
		SModel* GetModel(const std::string& pFileName);

		CTexture2D* LoadTexture(const std::string& pFileName);
		CTexture2D* GetTexture(const std::string& pFileName);

		CShader* LoadShader(EShaderType shaderType, const std::string& pFileName, const std::string& entryPoint);
		CShader* GetShader(EShaderType shaderType, const std::string& pFileName);

	private:
		CGraphics* m_pGraphics;
		CSysWindow* m_pSysWindow;
		std::unordered_map<std::string, SModel> m_models;
		std::unordered_map<std::string, CTexture2D*> m_textures;
		std::unordered_map<std::string, CShader*> m_shaders;
	};
}
