// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file cadenaPublisher.h
 * This header file contains the declaration of the publisher functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _CADENA_PUBLISHER_H_
#define _CADENA_PUBLISHER_H_

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>
#include "../topics/IDLGraphPubSubTypes.h"

class DSRPublisher
{
public:
    DSRPublisher();
    virtual ~DSRPublisher();
    bool init(eprosima::fastrtps::Participant *mp_participant_, const char *topicName, const char *topicDataType, bool isStreamData = false);
    [[nodiscard]] eprosima::fastrtps::rtps::GUID_t getParticipantID() const;
    bool write(IDL::GraphRequest *object);
    bool write(IDL::Mvreg *object);
    bool write(IDL::OrMap *object);
    bool write(IDL::MvregNodeAttr *object);
    bool write(IDL::MvregEdge *object);
    bool write(IDL::MvregEdgeAttr *object);

private:
	eprosima::fastrtps::Participant *mp_participant;
	eprosima::fastrtps::Publisher *mp_publisher;

	class PubListener : public eprosima::fastrtps::PublisherListener
	{
	public:
		PubListener() : n_matched(0){};
		~PubListener() override = default;
		void onPublicationMatched(eprosima::fastrtps::Publisher* pub,eprosima::fastrtps::rtps::MatchingInfo& info) override;
		int n_matched;
	} m_listener;

};

#endif // _CADENA_PUBLISHER_H_