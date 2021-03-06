/**
 *
 *  ItemController.cc
 *  This file is generated by drogon_ctl
 *
 */

#include "ItemController.h"
#include <string>


void ItemController::getOne(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback,
                            Item::PrimaryKeyType &&id)
{
    ItemControllerBase::getOne(req, std::move(callback), std::move(id));
}


void ItemController::updateOne(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               Item::PrimaryKeyType &&id)
{
    ItemControllerBase::updateOne(req, std::move(callback), std::move(id));
}


void ItemController::deleteOne(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback,
                               Item::PrimaryKeyType &&id)
{
    ItemControllerBase::deleteOne(req, std::move(callback), std::move(id));
}

void ItemController::get(const HttpRequestPtr &req,
                         std::function<void(const HttpResponsePtr &)> &&callback)
{
    ItemControllerBase::get(req, std::move(callback));
}

void ItemController::create(const HttpRequestPtr &req,
                            std::function<void(const HttpResponsePtr &)> &&callback)
{
    ItemControllerBase::create(req, std::move(callback));
}
