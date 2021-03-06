/**
 *
 *  Skill.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Skill.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::MaaGameData;

const std::string Skill::Cols::_skillId = "skillId";
const std::string Skill::Cols::_iconId = "iconId";
const std::string Skill::Cols::_hidden = "hidden";
const std::string Skill::Cols::_levels = "levels";
const std::string Skill::primaryKeyName = "skillId";
const bool Skill::hasPrimaryKey = true;
const std::string Skill::tableName = "skill";

const std::vector<typename Skill::MetaData> Skill::metaData_={
{"skillId","std::string","varchar(255)",255,0,1,1},
{"iconId","std::string","varchar(255)",255,0,0,0},
{"hidden","int8_t","tinyint(1)",1,0,0,0},
{"levels","std::string","json",0,0,0,0}
};
const std::string &Skill::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Skill::Skill(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["skillId"].isNull())
        {
            skillid_=std::make_shared<std::string>(r["skillId"].as<std::string>());
        }
        if(!r["iconId"].isNull())
        {
            iconid_=std::make_shared<std::string>(r["iconId"].as<std::string>());
        }
        if(!r["hidden"].isNull())
        {
            hidden_=std::make_shared<int8_t>(r["hidden"].as<int8_t>());
        }
        if(!r["levels"].isNull())
        {
            levels_=std::make_shared<std::string>(r["levels"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 4 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            skillid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            iconid_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            hidden_=std::make_shared<int8_t>(r[index].as<int8_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            levels_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Skill::Skill(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            skillid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            iconid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            hidden_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            levels_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
}

Skill::Skill(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("skillId"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["skillId"].isNull())
        {
            skillid_=std::make_shared<std::string>(pJson["skillId"].asString());
        }
    }
    if(pJson.isMember("iconId"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["iconId"].isNull())
        {
            iconid_=std::make_shared<std::string>(pJson["iconId"].asString());
        }
    }
    if(pJson.isMember("hidden"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["hidden"].isNull())
        {
            hidden_=std::make_shared<int8_t>((int8_t)pJson["hidden"].asInt64());
        }
    }
    if(pJson.isMember("levels"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["levels"].isNull())
        {
            levels_=std::make_shared<std::string>(pJson["levels"].asString());
        }
    }
}

void Skill::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 4)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            skillid_=std::make_shared<std::string>(pJson[pMasqueradingVector[0]].asString());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            iconid_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            hidden_=std::make_shared<int8_t>((int8_t)pJson[pMasqueradingVector[2]].asInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            levels_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
}

void Skill::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("skillId"))
    {
        if(!pJson["skillId"].isNull())
        {
            skillid_=std::make_shared<std::string>(pJson["skillId"].asString());
        }
    }
    if(pJson.isMember("iconId"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["iconId"].isNull())
        {
            iconid_=std::make_shared<std::string>(pJson["iconId"].asString());
        }
    }
    if(pJson.isMember("hidden"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["hidden"].isNull())
        {
            hidden_=std::make_shared<int8_t>((int8_t)pJson["hidden"].asInt64());
        }
    }
    if(pJson.isMember("levels"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["levels"].isNull())
        {
            levels_=std::make_shared<std::string>(pJson["levels"].asString());
        }
    }
}

const std::string &Skill::getValueOfSkillid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(skillid_)
        return *skillid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Skill::getSkillid() const noexcept
{
    return skillid_;
}
void Skill::setSkillid(const std::string &pSkillid) noexcept
{
    skillid_ = std::make_shared<std::string>(pSkillid);
    dirtyFlag_[0] = true;
}
void Skill::setSkillid(std::string &&pSkillid) noexcept
{
    skillid_ = std::make_shared<std::string>(std::move(pSkillid));
    dirtyFlag_[0] = true;
}
const typename Skill::PrimaryKeyType & Skill::getPrimaryKey() const
{
    assert(skillid_);
    return *skillid_;
}

const std::string &Skill::getValueOfIconid() const noexcept
{
    const static std::string defaultValue = std::string();
    if(iconid_)
        return *iconid_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Skill::getIconid() const noexcept
{
    return iconid_;
}
void Skill::setIconid(const std::string &pIconid) noexcept
{
    iconid_ = std::make_shared<std::string>(pIconid);
    dirtyFlag_[1] = true;
}
void Skill::setIconid(std::string &&pIconid) noexcept
{
    iconid_ = std::make_shared<std::string>(std::move(pIconid));
    dirtyFlag_[1] = true;
}
void Skill::setIconidToNull() noexcept
{
    iconid_.reset();
    dirtyFlag_[1] = true;
}

const int8_t &Skill::getValueOfHidden() const noexcept
{
    const static int8_t defaultValue = int8_t();
    if(hidden_)
        return *hidden_;
    return defaultValue;
}
const std::shared_ptr<int8_t> &Skill::getHidden() const noexcept
{
    return hidden_;
}
void Skill::setHidden(const int8_t &pHidden) noexcept
{
    hidden_ = std::make_shared<int8_t>(pHidden);
    dirtyFlag_[2] = true;
}
void Skill::setHiddenToNull() noexcept
{
    hidden_.reset();
    dirtyFlag_[2] = true;
}

const std::string &Skill::getValueOfLevels() const noexcept
{
    const static std::string defaultValue = std::string();
    if(levels_)
        return *levels_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Skill::getLevels() const noexcept
{
    return levels_;
}
void Skill::setLevels(const std::string &pLevels) noexcept
{
    levels_ = std::make_shared<std::string>(pLevels);
    dirtyFlag_[3] = true;
}
void Skill::setLevels(std::string &&pLevels) noexcept
{
    levels_ = std::make_shared<std::string>(std::move(pLevels));
    dirtyFlag_[3] = true;
}
void Skill::setLevelsToNull() noexcept
{
    levels_.reset();
    dirtyFlag_[3] = true;
}

void Skill::updateId(const uint64_t id)
{
}

const std::vector<std::string> &Skill::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "skillId",
        "iconId",
        "hidden",
        "levels"
    };
    return inCols;
}

void Skill::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getSkillid())
        {
            binder << getValueOfSkillid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getIconid())
        {
            binder << getValueOfIconid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getHidden())
        {
            binder << getValueOfHidden();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getLevels())
        {
            binder << getValueOfLevels();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Skill::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[0])
    {
        ret.push_back(getColumnName(0));
    }
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    return ret;
}

void Skill::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[0])
    {
        if(getSkillid())
        {
            binder << getValueOfSkillid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[1])
    {
        if(getIconid())
        {
            binder << getValueOfIconid();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getHidden())
        {
            binder << getValueOfHidden();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getLevels())
        {
            binder << getValueOfLevels();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Skill::toJson() const
{
    Json::Value ret;
    if(getSkillid())
    {
        ret["skillId"]=getValueOfSkillid();
    }
    else
    {
        ret["skillId"]=Json::Value();
    }
    if(getIconid())
    {
        ret["iconId"]=getValueOfIconid();
    }
    else
    {
        ret["iconId"]=Json::Value();
    }
    if(getHidden())
    {
        ret["hidden"]=getValueOfHidden();
    }
    else
    {
        ret["hidden"]=Json::Value();
    }
    if(getLevels())
    {
        ret["levels"]=getValueOfLevels();
    }
    else
    {
        ret["levels"]=Json::Value();
    }
    return ret;
}

Json::Value Skill::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 4)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getSkillid())
            {
                ret[pMasqueradingVector[0]]=getValueOfSkillid();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getIconid())
            {
                ret[pMasqueradingVector[1]]=getValueOfIconid();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getHidden())
            {
                ret[pMasqueradingVector[2]]=getValueOfHidden();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getLevels())
            {
                ret[pMasqueradingVector[3]]=getValueOfLevels();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getSkillid())
    {
        ret["skillId"]=getValueOfSkillid();
    }
    else
    {
        ret["skillId"]=Json::Value();
    }
    if(getIconid())
    {
        ret["iconId"]=getValueOfIconid();
    }
    else
    {
        ret["iconId"]=Json::Value();
    }
    if(getHidden())
    {
        ret["hidden"]=getValueOfHidden();
    }
    else
    {
        ret["hidden"]=Json::Value();
    }
    if(getLevels())
    {
        ret["levels"]=getValueOfLevels();
    }
    else
    {
        ret["levels"]=Json::Value();
    }
    return ret;
}

bool Skill::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("skillId"))
    {
        if(!validJsonOfField(0, "skillId", pJson["skillId"], err, true))
            return false;
    }
    else
    {
        err="The skillId column cannot be null";
        return false;
    }
    if(pJson.isMember("iconId"))
    {
        if(!validJsonOfField(1, "iconId", pJson["iconId"], err, true))
            return false;
    }
    if(pJson.isMember("hidden"))
    {
        if(!validJsonOfField(2, "hidden", pJson["hidden"], err, true))
            return false;
    }
    if(pJson.isMember("levels"))
    {
        if(!validJsonOfField(3, "levels", pJson["levels"], err, true))
            return false;
    }
    return true;
}
bool Skill::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
        else
        {
            err="The " + pMasqueradingVector[0] + " column cannot be null";
            return false;
        }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Skill::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("skillId"))
    {
        if(!validJsonOfField(0, "skillId", pJson["skillId"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("iconId"))
    {
        if(!validJsonOfField(1, "iconId", pJson["iconId"], err, false))
            return false;
    }
    if(pJson.isMember("hidden"))
    {
        if(!validJsonOfField(2, "hidden", pJson["hidden"], err, false))
            return false;
    }
    if(pJson.isMember("levels"))
    {
        if(!validJsonOfField(3, "levels", pJson["levels"], err, false))
            return false;
    }
    return true;
}
bool Skill::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                             const std::vector<std::string> &pMasqueradingVector,
                                             std::string &err)
{
    if(pMasqueradingVector.size() != 4)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Skill::validJsonOfField(size_t index,
                             const std::string &fieldName,
                             const Json::Value &pJson,
                             std::string &err,
                             bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
