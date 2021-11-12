import React from 'react';

import './Chat-Title.css';

const ChatTitle = ({ selectedConversation, onDeleteConversation }) => {
    return (
        <div id="chat-title">
            <span>{selectedConversation.title}</span>
            <img src={require("../../images/icons/trash-logo.svg").default}
                alt="Delete Conversation"
                onClick={() => { onDeleteConversation(); }} />
        </div>
    );
}

export default ChatTitle;