/***
* The MIT License (MIT)
*
* Copyright (c) 2015 DocumentDBCpp
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
***/

#ifndef _DOCUMENTDB_ATTACHMENT_ITERATOR_H_
#define _DOCUMENTDB_ATTACHMENT_ITERATOR_H_

#include <memory>

#include <cpprest/json.h>

#include "DocumentDBConfiguration.h"
#include "Attachment.h"

namespace documentdb
{
	class Document; // forward declaration

	class AttachmentIterator
	{
	public:
		AttachmentIterator(
			const std::shared_ptr<const Document>& document,
			const std::wstring& original_query,
			const int page_size,
			const std::wstring& original_request_uri,
			const std::wstring& continuation_id,
			const web::json::value& buffer);
		virtual ~AttachmentIterator();

		bool HasMore();

		std::shared_ptr<Attachment> Next();

	private:
		std::shared_ptr<const Document> document_;
		std::wstring original_query_;
		int page_size_;
		std::wstring original_request_uri_;
		std::wstring continuation_id_;
		web::json::value buffer_;
		unsigned int current_;
	};
}

#endif // !_DOCUMENTDB_ATTACHMENT_ITERATOR_H_
