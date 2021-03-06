/**
 *
 *  Zone.h
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#pragma once
#include <drogon/orm/Result.h>
#include <drogon/orm/Row.h>
#include <drogon/orm/Field.h>
#include <drogon/orm/SqlBinder.h>
#include <drogon/orm/Mapper.h>
#ifdef __cpp_impl_coroutine
#include <drogon/orm/CoroMapper.h>
#endif
#include <trantor/utils/Date.h>
#include <trantor/utils/Logger.h>
#include <json/json.h>
#include <string>
#include <memory>
#include <vector>
#include <tuple>
#include <stdint.h>
#include <iostream>

namespace drogon
{
namespace orm
{
class DbClient;
using DbClientPtr = std::shared_ptr<DbClient>;
}
}
namespace drogon_model
{
namespace MaaGameData
{

class Zone
{
  public:
    struct Cols
    {
        static const std::string _zoneId;
        static const std::string _zoneIndex;
        static const std::string _type;
        static const std::string _zoneNameFirst;
        static const std::string _zoneNameSecond;
        static const std::string _zoneNameTitleCurrent;
        static const std::string _zoneNameTitleUncurrent;
        static const std::string _zoneNameTitleEx;
        static const std::string _zoneNameThird;
        static const std::string _lockedText;
        static const std::string _canPreview;
    };

    const static int primaryKeyNumber;
    const static std::string tableName;
    const static bool hasPrimaryKey;
    const static std::string primaryKeyName;
    using PrimaryKeyType = std::string;
    const PrimaryKeyType &getPrimaryKey() const;

    /**
     * @brief constructor
     * @param r One row of records in the SQL query result.
     * @param indexOffset Set the offset to -1 to access all columns by column names,
     * otherwise access all columns by offsets.
     * @note If the SQL is not a style of 'select * from table_name ...' (select all
     * columns by an asterisk), please set the offset to -1.
     */
    explicit Zone(const drogon::orm::Row &r, const ssize_t indexOffset = 0) noexcept;

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     */
    explicit Zone(const Json::Value &pJson) noexcept(false);

    /**
     * @brief constructor
     * @param pJson The json object to construct a new instance.
     * @param pMasqueradingVector The aliases of table columns.
     */
    Zone(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false);

    Zone() = default;

    void updateByJson(const Json::Value &pJson) noexcept(false);
    void updateByMasqueradedJson(const Json::Value &pJson,
                                 const std::vector<std::string> &pMasqueradingVector) noexcept(false);
    static bool validateJsonForCreation(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForCreation(const Json::Value &,
                                                const std::vector<std::string> &pMasqueradingVector,
                                                    std::string &err);
    static bool validateJsonForUpdate(const Json::Value &pJson, std::string &err);
    static bool validateMasqueradedJsonForUpdate(const Json::Value &,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err);
    static bool validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson,
                          std::string &err,
                          bool isForCreation);

    /**  For column zoneId  */
    ///Get the value of the column zoneId, returns the default value if the column is null
    const std::string &getValueOfZoneid() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZoneid() const noexcept;
    ///Set the value of the column zoneId
    void setZoneid(const std::string &pZoneid) noexcept;
    void setZoneid(std::string &&pZoneid) noexcept;

    /**  For column zoneIndex  */
    ///Get the value of the column zoneIndex, returns the default value if the column is null
    const int32_t &getValueOfZoneindex() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int32_t> &getZoneindex() const noexcept;
    ///Set the value of the column zoneIndex
    void setZoneindex(const int32_t &pZoneindex) noexcept;
    void setZoneindexToNull() noexcept;

    /**  For column type  */
    ///Get the value of the column type, returns the default value if the column is null
    const std::string &getValueOfType() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getType() const noexcept;
    ///Set the value of the column type
    void setType(const std::string &pType) noexcept;
    void setType(std::string &&pType) noexcept;
    void setTypeToNull() noexcept;

    /**  For column zoneNameFirst  */
    ///Get the value of the column zoneNameFirst, returns the default value if the column is null
    const std::string &getValueOfZonenamefirst() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenamefirst() const noexcept;
    ///Set the value of the column zoneNameFirst
    void setZonenamefirst(const std::string &pZonenamefirst) noexcept;
    void setZonenamefirst(std::string &&pZonenamefirst) noexcept;
    void setZonenamefirstToNull() noexcept;

    /**  For column zoneNameSecond  */
    ///Get the value of the column zoneNameSecond, returns the default value if the column is null
    const std::string &getValueOfZonenamesecond() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenamesecond() const noexcept;
    ///Set the value of the column zoneNameSecond
    void setZonenamesecond(const std::string &pZonenamesecond) noexcept;
    void setZonenamesecond(std::string &&pZonenamesecond) noexcept;
    void setZonenamesecondToNull() noexcept;

    /**  For column zoneNameTitleCurrent  */
    ///Get the value of the column zoneNameTitleCurrent, returns the default value if the column is null
    const std::string &getValueOfZonenametitlecurrent() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenametitlecurrent() const noexcept;
    ///Set the value of the column zoneNameTitleCurrent
    void setZonenametitlecurrent(const std::string &pZonenametitlecurrent) noexcept;
    void setZonenametitlecurrent(std::string &&pZonenametitlecurrent) noexcept;
    void setZonenametitlecurrentToNull() noexcept;

    /**  For column zoneNameTitleUncurrent  */
    ///Get the value of the column zoneNameTitleUncurrent, returns the default value if the column is null
    const std::string &getValueOfZonenametitleuncurrent() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenametitleuncurrent() const noexcept;
    ///Set the value of the column zoneNameTitleUncurrent
    void setZonenametitleuncurrent(const std::string &pZonenametitleuncurrent) noexcept;
    void setZonenametitleuncurrent(std::string &&pZonenametitleuncurrent) noexcept;
    void setZonenametitleuncurrentToNull() noexcept;

    /**  For column zoneNameTitleEx  */
    ///Get the value of the column zoneNameTitleEx, returns the default value if the column is null
    const std::string &getValueOfZonenametitleex() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenametitleex() const noexcept;
    ///Set the value of the column zoneNameTitleEx
    void setZonenametitleex(const std::string &pZonenametitleex) noexcept;
    void setZonenametitleex(std::string &&pZonenametitleex) noexcept;
    void setZonenametitleexToNull() noexcept;

    /**  For column zoneNameThird  */
    ///Get the value of the column zoneNameThird, returns the default value if the column is null
    const std::string &getValueOfZonenamethird() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getZonenamethird() const noexcept;
    ///Set the value of the column zoneNameThird
    void setZonenamethird(const std::string &pZonenamethird) noexcept;
    void setZonenamethird(std::string &&pZonenamethird) noexcept;
    void setZonenamethirdToNull() noexcept;

    /**  For column lockedText  */
    ///Get the value of the column lockedText, returns the default value if the column is null
    const std::string &getValueOfLockedtext() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<std::string> &getLockedtext() const noexcept;
    ///Set the value of the column lockedText
    void setLockedtext(const std::string &pLockedtext) noexcept;
    void setLockedtext(std::string &&pLockedtext) noexcept;
    void setLockedtextToNull() noexcept;

    /**  For column canPreview  */
    ///Get the value of the column canPreview, returns the default value if the column is null
    const int8_t &getValueOfCanpreview() const noexcept;
    ///Return a shared_ptr object pointing to the column const value, or an empty shared_ptr object if the column is null
    const std::shared_ptr<int8_t> &getCanpreview() const noexcept;
    ///Set the value of the column canPreview
    void setCanpreview(const int8_t &pCanpreview) noexcept;
    void setCanpreviewToNull() noexcept;


    static size_t getColumnNumber() noexcept {  return 11;  }
    static const std::string &getColumnName(size_t index) noexcept(false);

    Json::Value toJson() const;
    Json::Value toMasqueradedJson(const std::vector<std::string> &pMasqueradingVector) const;
    /// Relationship interfaces
  private:
    friend drogon::orm::Mapper<Zone>;
#ifdef __cpp_impl_coroutine
    friend drogon::orm::CoroMapper<Zone>;
#endif
    static const std::vector<std::string> &insertColumns() noexcept;
    void outputArgs(drogon::orm::internal::SqlBinder &binder) const;
    const std::vector<std::string> updateColumns() const;
    void updateArgs(drogon::orm::internal::SqlBinder &binder) const;
    ///For mysql or sqlite3
    void updateId(const uint64_t id);
    std::shared_ptr<std::string> zoneid_;
    std::shared_ptr<int32_t> zoneindex_;
    std::shared_ptr<std::string> type_;
    std::shared_ptr<std::string> zonenamefirst_;
    std::shared_ptr<std::string> zonenamesecond_;
    std::shared_ptr<std::string> zonenametitlecurrent_;
    std::shared_ptr<std::string> zonenametitleuncurrent_;
    std::shared_ptr<std::string> zonenametitleex_;
    std::shared_ptr<std::string> zonenamethird_;
    std::shared_ptr<std::string> lockedtext_;
    std::shared_ptr<int8_t> canpreview_;
    struct MetaData
    {
        const std::string colName_;
        const std::string colType_;
        const std::string colDatabaseType_;
        const ssize_t colLength_;
        const bool isAutoVal_;
        const bool isPrimaryKey_;
        const bool notNull_;
    };
    static const std::vector<MetaData> metaData_;
    bool dirtyFlag_[11]={ false };
  public:
    static const std::string &sqlForFindingByPrimaryKey()
    {
        static const std::string sql="select * from " + tableName + " where zoneId = ?";
        return sql;
    }

    static const std::string &sqlForDeletingByPrimaryKey()
    {
        static const std::string sql="delete from " + tableName + " where zoneId = ?";
        return sql;
    }
    std::string sqlForInserting(bool &needSelection) const
    {
        std::string sql="insert into " + tableName + " (";
        size_t parametersCount = 0;
        needSelection = false;
        if(dirtyFlag_[0])
        {
            sql += "zoneId,";
            ++parametersCount;
        }
        if(dirtyFlag_[1])
        {
            sql += "zoneIndex,";
            ++parametersCount;
        }
        if(dirtyFlag_[2])
        {
            sql += "type,";
            ++parametersCount;
        }
        if(dirtyFlag_[3])
        {
            sql += "zoneNameFirst,";
            ++parametersCount;
        }
        if(dirtyFlag_[4])
        {
            sql += "zoneNameSecond,";
            ++parametersCount;
        }
        if(dirtyFlag_[5])
        {
            sql += "zoneNameTitleCurrent,";
            ++parametersCount;
        }
        if(dirtyFlag_[6])
        {
            sql += "zoneNameTitleUncurrent,";
            ++parametersCount;
        }
        if(dirtyFlag_[7])
        {
            sql += "zoneNameTitleEx,";
            ++parametersCount;
        }
        if(dirtyFlag_[8])
        {
            sql += "zoneNameThird,";
            ++parametersCount;
        }
        if(dirtyFlag_[9])
        {
            sql += "lockedText,";
            ++parametersCount;
        }
        if(dirtyFlag_[10])
        {
            sql += "canPreview,";
            ++parametersCount;
        }
        if(parametersCount > 0)
        {
            sql[sql.length()-1]=')';
            sql += " values (";
        }
        else
            sql += ") values (";

        if(dirtyFlag_[0])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[1])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[2])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[3])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[4])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[5])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[6])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[7])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[8])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[9])
        {
            sql.append("?,");

        }
        if(dirtyFlag_[10])
        {
            sql.append("?,");

        }
        if(parametersCount > 0)
        {
            sql.resize(sql.length() - 1);
        }
        sql.append(1, ')');
        LOG_TRACE << sql;
        return sql;
    }
};
} // namespace MaaGameData
} // namespace drogon_model
