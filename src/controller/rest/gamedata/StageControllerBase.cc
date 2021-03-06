
/**
 *
 *  StageControllerBase.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl automatically.
 *  Users should implement business logic in the derived class.
 */

#include "StageControllerBase.h"
#include <string>

void StageControllerBase::getOne(const HttpRequestPtr &req,
                                 std::function<void(const HttpResponsePtr &)> &&callback,
                                 Stage::PrimaryKeyType &&id)
{

    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    drogon::orm::Mapper<Stage> mapper(dbClientPtr);
    mapper.findByPrimaryKey(
        id,
        [req, callbackPtr, this](Stage r) {
            (*callbackPtr)(HttpResponse::newHttpJsonResponse(makeJson(req, r)));
        },
        [callbackPtr](const DrogonDbException &e) {
            const drogon::orm::UnexpectedRows *s=dynamic_cast<const drogon::orm::UnexpectedRows *>(&e.base());
            if(s)
            {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(k404NotFound);
                (*callbackPtr)(resp);
                return;
            }
            LOG_ERROR<<e.base().what();
            Json::Value ret;
            ret["error"] = "database error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k500InternalServerError);
            (*callbackPtr)(resp);
        });
}


void StageControllerBase::updateOne(const HttpRequestPtr &req,
                                    std::function<void(const HttpResponsePtr &)> &&callback,
                                    Stage::PrimaryKeyType &&id)
{
    auto jsonPtr=req->jsonObject();
    if(!jsonPtr)
    {
        Json::Value ret;
        ret["error"]="No json object is found in the request";
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    Stage object;
    std::string err;
    if(!doCustomValidations(*jsonPtr, err))
    {
        Json::Value ret;
        ret["error"] = err;
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    try
    {
        if(isMasquerading())
        {
            if(!Stage::validateMasqueradedJsonForUpdate(*jsonPtr, masqueradingVector(), err))
            {
                Json::Value ret;
                ret["error"] = err;
                auto resp= HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k400BadRequest);
                callback(resp);
                return;
            }
            object.updateByMasqueradedJson(*jsonPtr, masqueradingVector());
        }
        else
        {
            if(!Stage::validateJsonForUpdate(*jsonPtr, err))
            {
                Json::Value ret;
                ret["error"] = err;
                auto resp= HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k400BadRequest);
                callback(resp);
                return;
            }
            object.updateByJson(*jsonPtr);
        }
    }
    catch(const Json::Exception &e)
    {
        LOG_ERROR << e.what();
        Json::Value ret;
        ret["error"]="Field type error";
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;        
    }
    if(object.getPrimaryKey() != id)
    {
        Json::Value ret;
        ret["error"]="Bad primary key";
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }

    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    drogon::orm::Mapper<Stage> mapper(dbClientPtr);

    mapper.update(
        object,
        [callbackPtr](const size_t count) 
        {
            if(count == 1)
            {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(k202Accepted);
                (*callbackPtr)(resp);
            }
            else if(count == 0)
            {
                Json::Value ret;
                ret["error"]="No resources are updated";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k404NotFound);
                (*callbackPtr)(resp);
            }
            else
            {
                LOG_FATAL << "More than one resource is updated: " << count;
                Json::Value ret;
                ret["error"] = "database error";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k500InternalServerError);
                (*callbackPtr)(resp);
            }
        },
        [callbackPtr](const DrogonDbException &e) {
            LOG_ERROR << e.base().what();
            Json::Value ret;
            ret["error"] = "database error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k500InternalServerError);
            (*callbackPtr)(resp);
        });
}


void StageControllerBase::deleteOne(const HttpRequestPtr &req,
                                    std::function<void(const HttpResponsePtr &)> &&callback,
                                    Stage::PrimaryKeyType &&id)
{

    auto dbClientPtr = getDbClient();
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    drogon::orm::Mapper<Stage> mapper(dbClientPtr);
    mapper.deleteByPrimaryKey(
        id,
        [callbackPtr](const size_t count) {
            if(count == 1)
            {
                auto resp = HttpResponse::newHttpResponse();
                resp->setStatusCode(k204NoContent);
                (*callbackPtr)(resp);
            }
            else if(count == 0)
            {
                Json::Value ret;
                ret["error"] = "No resources deleted";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k404NotFound);
                (*callbackPtr)(resp);
            }
            else
            {
                LOG_FATAL << "Delete more than one records: " << count;
                Json::Value ret;
                ret["error"] = "Database error";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k500InternalServerError);
                (*callbackPtr)(resp);
            }
        },
        [callbackPtr](const DrogonDbException &e) {
            LOG_ERROR << e.base().what();
            Json::Value ret;
            ret["error"] = "database error";
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k500InternalServerError);
            (*callbackPtr)(resp);
        });
}

void StageControllerBase::get(const HttpRequestPtr &req,
                              std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto dbClientPtr = getDbClient();
    drogon::orm::Mapper<Stage> mapper(dbClientPtr);
    auto &parameters = req->parameters();
    auto iter = parameters.find("sort");
    if(iter != parameters.end())
    {
        auto sortFields = drogon::utils::splitString(iter->second, ",");
        for(auto &field : sortFields)
        {
            if(field.empty())
                continue;
            if(field[0] == '+')
            {
                field = field.substr(1);
                mapper.orderBy(field, SortOrder::ASC);
            }
            else if(field[0] == '-')
            {
                field = field.substr(1);
                mapper.orderBy(field, SortOrder::DESC);
            }
            else
            {
                mapper.orderBy(field, SortOrder::ASC);
            }
        }
    }
    iter = parameters.find("offset");
    if(iter != parameters.end())
    {
        try{
            auto offset = std::stoll(iter->second);
            mapper.offset(offset);
        }
        catch(...)
        {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k400BadRequest);
            callback(resp);
            return;
        }
    }
    iter = parameters.find("limit");
    if(iter != parameters.end())
    {
        try{
            auto limit = std::stoll(iter->second);
            mapper.limit(limit);
        }
        catch(...)
        {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k400BadRequest);
            callback(resp);
            return;
        }
    }    
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));
    auto jsonPtr = req->jsonObject();
    if(jsonPtr && jsonPtr->isMember("filter"))
    {
        try{
            auto criteria = makeCriteria((*jsonPtr)["filter"]);
            mapper.findBy(criteria,
                [req, callbackPtr, this](const std::vector<Stage> &v) {
                    Json::Value ret;
                    ret.resize(0);
                    for (auto &obj : v)
                    {
                        ret.append(makeJson(req, obj));
                    }
                    (*callbackPtr)(HttpResponse::newHttpJsonResponse(ret));
                },
                [callbackPtr](const DrogonDbException &e) { 
                    LOG_ERROR << e.base().what();
                    Json::Value ret;
                    ret["error"] = "database error";
                    auto resp = HttpResponse::newHttpJsonResponse(ret);
                    resp->setStatusCode(k500InternalServerError);
                    (*callbackPtr)(resp);    
                });
        }
        catch(const std::exception &e)
        {
            LOG_ERROR << e.what();
            Json::Value ret;
            ret["error"] = e.what();
            auto resp = HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k400BadRequest);
            (*callbackPtr)(resp);
            return;    
        }
    }
    else
    {
        mapper.findAll([req, callbackPtr, this](const std::vector<Stage> &v) {
                Json::Value ret;
                ret.resize(0);
                for (auto &obj : v)
                {
                    ret.append(makeJson(req, obj));
                }
                (*callbackPtr)(HttpResponse::newHttpJsonResponse(ret));
            },
            [callbackPtr](const DrogonDbException &e) { 
                LOG_ERROR << e.base().what();
                Json::Value ret;
                ret["error"] = "database error";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k500InternalServerError);
                (*callbackPtr)(resp);    
            });
    }
}

void StageControllerBase::create(const HttpRequestPtr &req,
                                 std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto jsonPtr=req->jsonObject();
    if(!jsonPtr)
    {
        Json::Value ret;
        ret["error"]="No json object is found in the request";
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    std::string err;
    if(!doCustomValidations(*jsonPtr, err))
    {
        Json::Value ret;
        ret["error"] = err;
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;
    }
    if(isMasquerading())
    {
        if(!Stage::validateMasqueradedJsonForCreation(*jsonPtr, masqueradingVector(), err))
        {
            Json::Value ret;
            ret["error"] = err;
            auto resp= HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k400BadRequest);
            callback(resp);
            return;
        }
    }
    else
    {
        if(!Stage::validateJsonForCreation(*jsonPtr, err))
        {
            Json::Value ret;
            ret["error"] = err;
            auto resp= HttpResponse::newHttpJsonResponse(ret);
            resp->setStatusCode(k400BadRequest);
            callback(resp);
            return;
        }
    }   
    try 
    {
        Stage object = 
            (isMasquerading()? 
             Stage(*jsonPtr, masqueradingVector()) : 
             Stage(*jsonPtr));
        auto dbClientPtr = getDbClient();
        auto callbackPtr =
            std::make_shared<std::function<void(const HttpResponsePtr &)>>(
                std::move(callback));
        drogon::orm::Mapper<Stage> mapper(dbClientPtr);
        mapper.insert(
            object,
            [req, callbackPtr, this](Stage newObject){
                (*callbackPtr)(HttpResponse::newHttpJsonResponse(
                    makeJson(req, newObject)));
            },
            [callbackPtr](const DrogonDbException &e){
                LOG_ERROR << e.base().what();
                Json::Value ret;
                ret["error"] = "database error";
                auto resp = HttpResponse::newHttpJsonResponse(ret);
                resp->setStatusCode(k500InternalServerError);
                (*callbackPtr)(resp);   
            });
    }
    catch(const Json::Exception &e)
    {
        LOG_ERROR << e.what();
        Json::Value ret;
        ret["error"]="Field type error";
        auto resp= HttpResponse::newHttpJsonResponse(ret);
        resp->setStatusCode(k400BadRequest);
        callback(resp);
        return;        
    }   
}

/*
void StageControllerBase::update(const HttpRequestPtr &req,
                                 std::function<void(const HttpResponsePtr &)> &&callback)
{

}*/

StageControllerBase::StageControllerBase()
    : RestfulController({
          "stageId",
          "stageType",
          "difficulty",
          "performanceStageFlag",
          "unlockCondition",
          "levelId",
          "zoneId",
          "code",
          "name",
          "description",
          "hardStageId",
          "dangerLevel",
          "dangerPoint",
          "loadingPicId",
          "canPractice",
          "canBattleReplay",
          "apCost",
          "apFailReturn",
          "etItemId",
          "etCost",
          "etFailReturn",
          "etButtonStyle",
          "apProtectTimes",
          "diamondOnceDrop",
          "practiceTicketCost",
          "dailyStageDifficulty",
          "expGain",
          "goldGain",
          "loseExpGain",
          "loseGoldGain",
          "passFavor",
          "completeFavor",
          "slProgress",
          "displayMainItem",
          "hilightMark",
          "bossMark",
          "isPredefined",
          "isHardPredefined",
          "isSkillSelectablePredefined",
          "isStoryOnly",
          "appearanceStyle",
          "startButtonOverrideId",
          "isStagePatch",
          "mainStageId"
      })
{
   /**
    * The items in the vector are aliases of column names in the table.
    * if one item is set to an empty string, the related column is not sent
    * to clients.
    */
    enableMasquerading({
        "stageId", // the alias for the stageId column.
        "stageType", // the alias for the stageType column.
        "difficulty", // the alias for the difficulty column.
        "performanceStageFlag", // the alias for the performanceStageFlag column.
        "unlockCondition", // the alias for the unlockCondition column.
        "levelId", // the alias for the levelId column.
        "zoneId", // the alias for the zoneId column.
        "code", // the alias for the code column.
        "name", // the alias for the name column.
        "description", // the alias for the description column.
        "hardStageId", // the alias for the hardStageId column.
        "dangerLevel", // the alias for the dangerLevel column.
        "dangerPoint", // the alias for the dangerPoint column.
        "loadingPicId", // the alias for the loadingPicId column.
        "canPractice", // the alias for the canPractice column.
        "canBattleReplay", // the alias for the canBattleReplay column.
        "apCost", // the alias for the apCost column.
        "apFailReturn", // the alias for the apFailReturn column.
        "etItemId", // the alias for the etItemId column.
        "etCost", // the alias for the etCost column.
        "etFailReturn", // the alias for the etFailReturn column.
        "etButtonStyle", // the alias for the etButtonStyle column.
        "apProtectTimes", // the alias for the apProtectTimes column.
        "diamondOnceDrop", // the alias for the diamondOnceDrop column.
        "practiceTicketCost", // the alias for the practiceTicketCost column.
        "dailyStageDifficulty", // the alias for the dailyStageDifficulty column.
        "expGain", // the alias for the expGain column.
        "goldGain", // the alias for the goldGain column.
        "loseExpGain", // the alias for the loseExpGain column.
        "loseGoldGain", // the alias for the loseGoldGain column.
        "passFavor", // the alias for the passFavor column.
        "completeFavor", // the alias for the completeFavor column.
        "slProgress", // the alias for the slProgress column.
        "displayMainItem", // the alias for the displayMainItem column.
        "hilightMark", // the alias for the hilightMark column.
        "bossMark", // the alias for the bossMark column.
        "isPredefined", // the alias for the isPredefined column.
        "isHardPredefined", // the alias for the isHardPredefined column.
        "isSkillSelectablePredefined", // the alias for the isSkillSelectablePredefined column.
        "isStoryOnly", // the alias for the isStoryOnly column.
        "appearanceStyle", // the alias for the appearanceStyle column.
        "startButtonOverrideId", // the alias for the startButtonOverrideId column.
        "isStagePatch", // the alias for the isStagePatch column.
        "mainStageId"  // the alias for the mainStageId column.
    });
}
