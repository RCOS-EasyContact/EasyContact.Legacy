import React from 'react';

import './Chat-Form.css';

const ChatTitle = ({ selectedConversation }) => {
    return (
        <div id="chat-title">
            <span>{selectedConversation.title}</span>
            <img src={require("../../images/icons/trash-logo.svg")} alt="Delete Conversation" />
        </div>
    );
}
export default ChatForm;

