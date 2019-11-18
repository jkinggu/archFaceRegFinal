#pragma once

#ifndef FACEREG_PAGERESULT_H
#define FACEREG_PAGERESULT_H
#include <Qvector>
template <typename T>
struct PageResult {
	//返回具体对象集合相当于Java的list我们用模版
	QVector<T> resList;
	int totalCount;
	int currentPage = 1;
	int pageSize = 25;
	int firstPage = 1;
	int next;
	int previous;
	int totalPage;
public:
	PageResult() {};
	PageResult(QVector<T> resLis, int totalCount, int currentPage) {
		this->resList = resLis;
		this->totalCount = totalCount;
		this->currentPage = currentPage;
		this->totalPage = this->totalCount%this->pageSize == 0 ? (this->totalCount / this->pageSize == 0 ? 1 : totalCount / this->pageSize + 1) :
			(this->totalCount / this->pageSize + 1);
		this->next = this->currentPage<this->totalPage ? this->currentPage + 1 : this->totalPage;
		this->previous = this->currentPage>1 ? this->currentPage - 1 : 1;
	}

};

#endif //FACEREG_PAGERESULT_H
