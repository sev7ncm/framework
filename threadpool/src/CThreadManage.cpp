/* Copyright(C)
* For free
* All right reserved
* 
*/
/**
* @file CThreadManage.cpp
* @brief 线程池管理类
* @author highway-9, 787280310@qq.com
* @version 1.1.0
* @date 2016-02-17
*/

#include "CThreadManage.h"
#include "CThreadPool.h"
#include "CJob.h"

CThreadManage::CThreadManage()
{
    m_threadPool.reset();
    if (m_threadPool == NULL)
    {
        m_threadPool = boost::make_shared<CThreadPool>();
    }
}

CThreadManage::~CThreadManage()
{
    assert(m_threadPool != NULL);
    m_threadPool->terminateAll();
}

void CThreadManage::initThreadNum(unsigned int initNumOfThread)
{
    assert(m_threadPool != NULL);
    m_threadPool->initThreadNum(initNumOfThread);
}

void CThreadManage::run(CJobPtr job, void *jobData)
{
    assert(m_threadPool != NULL);
    m_threadPool->run(job, jobData);
}

void CThreadManage::terminateAll()
{
    assert(m_threadPool != NULL);
    m_threadPool->terminateAll();
}
