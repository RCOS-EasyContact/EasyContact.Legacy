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
const ChatShell = (
    {
        conversations,
        selectedConversation,
        conversationChanged
    }) => {
    return (
        <div id="chat-container">
            <ConversationSearch />
            <ConversationList
                onConversationItemSelected={conversationChanged}
                conversations={conversations}
                selectedConversationId={selectedConversation.id} />
            <NewConversation />
            <ChatTitle selectedConversation={selectedConversation} />
            <MessageList messages={selectedConversation.messages} />
            <ChatForm />
        </div>
    );
}

const mapStateToProps = state => {
    return {
        conversations: state.conversationState.conversations,
        selectedConversation: state.conversationState.selectedConversation
    };
};

const mapDispatchToProps = dispatch => ({
    conversationChanged: conversationId => dispatch(conversationChanged(conversationId))
});

export default connect(
    mapStateToProps,
    mapDispatchToProps
)(ChatShell);