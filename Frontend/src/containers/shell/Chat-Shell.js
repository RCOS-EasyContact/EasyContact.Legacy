import React from 'react';
import { connect } from 'react-redux';

import { conversationChanged } from '../../actions';
import NewConversation from '../../components/conversation/new-conversation/New-Conversation';
import ChatTitle from '../../components/chat-title/Chat-Title'
import ConversationList from '../../components/conversation/conversation-list/Conversation-List'
import ConversationSearch from '../../components/conversation/conversation-search/Conversation-Search'
import MessageList from '../../components/message/Message-List';
import ChatForm from '../../components/chat-form/Chat-Form';

import './Chat-Shell.css';
import { useState } from 'react';

const ChatShell = ({ conversations }) => {
    const [selectedConvo] = useState(selectedConversation);
    return (
        <div id="chat-container">
            <ConversationSearch />
            <ConversationList
                conversations={conversations}
                selectedConversationId={selectedConvo.id}
            />
            <NewConversation />
            <ChatTitle selectedConversation={selectedConversation} />
            <MessageList messages={messages} />
            <ChatForm />
        </div>
    );
}

export default ChatShell;