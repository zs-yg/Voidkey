export function loadGithubContent() {
    const contentElement = document.getElementById('content');
    
    const section = document.createElement('section');
    section.innerHTML = `
        <h2>GitHub 仓库</h2>
        <div class="github-links">
            <p>Release 链接: 
                <span id="release-link">https://github.com/zs-yg/Voidkey/releases</span>
                <button id="copy-release">复制</button>
            </p>
            <p>Code 链接: 
                <span id="code-link">https://github.com/zs-yg/Voidkey/</span>
                <button id="copy-code">复制</button>
            </p>
        </div>
    `;
    
    contentElement.appendChild(section);

    // 添加复制功能
    document.getElementById('copy-release').addEventListener('click', () => {
        const releaseLink = document.getElementById('release-link').textContent;
        navigator.clipboard.writeText(releaseLink)
            .then(() => alert('Release链接已复制到剪贴板'))
            .catch(err => console.error('复制失败:', err));
    });

    document.getElementById('copy-code').addEventListener('click', () => {
        const codeLink = document.getElementById('code-link').textContent;
        navigator.clipboard.writeText(codeLink)
            .then(() => alert('Code链接已复制到剪贴板'))
            .catch(err => console.error('复制失败:', err));
    });
}
