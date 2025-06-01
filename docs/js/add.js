export function loadAddContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>加入我们</h2>
        <div class="qq-group">
            <p>QQ群号: <span id="qq-group-number">1043867176</span></p>
            <button id="copy-btn">复制群号</button>
        </div>
    `;
    
    contentElement.appendChild(section);

    // 添加复制功能
    document.getElementById('copy-btn').addEventListener('click', () => {
        const qqNumber = document.getElementById('qq-group-number').textContent;
        navigator.clipboard.writeText(qqNumber)
            .then(() => alert('群号已复制到剪贴板'))
            .catch(err => console.error('复制失败:', err));
    });
}
