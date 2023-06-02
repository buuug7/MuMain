/**************************************************************************************************

스크립트 목록 최 상위 객체

카테고리 목록, 패키지 목록, 상품(속성) 목록을 가지고 있다.

**************************************************************************************************/

#pragma once

#include "ShopPackage.h"
#include "ShopProduct.h"

#include "ShopCategoryList.h"
#include "ShopPackageList.h"
#include "ShopProductList.h"

class CShopList
{
public:
    CShopList();
    virtual ~CShopList();

    WZResult LoadCategroy(const char* szFilePath);
    WZResult LoadPackage(const char* szFilePath);
    WZResult LoadProduct(const char* szFilePath);

    CShopCategoryList* GetCategoryListPtr() { return m_CategoryListPtr; };	// 카테고리 목록 가져온다.
    CShopPackageList* GetPackageListPtr() { return m_PackageListPtr; };		// 패키지 목록 가져온다.
    CShopProductList* GetProductListPtr() { return m_ProductListPtr; };		// 상품(속성) 목록 가져온다.

    void SetCategoryListPtr(CShopCategoryList* CategoryListPtr);
    void SetPackageListPtr(CShopPackageList* PackagePtr);
    void SetProductListPtr(CShopProductList* ProductListPtr);

private:
    CShopCategoryList* m_CategoryListPtr;
    CShopPackageList* m_PackageListPtr;
    CShopProductList* m_ProductListPtr;

    FILE_ENCODE IsFileEncodingUtf8(const char* szFilePath);
    std::string GetDecodeingString(const char* str, FILE_ENCODE encode);
};